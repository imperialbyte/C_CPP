// Pong with raylib
#include "raylib.h"

struct Ball {

    float x, y;
    float speedX, speedY;
    float radius;
    Color color;

    void DrawBall() {
        DrawCircle((int) x,(int) y, radius, color); // ball
    }

};


struct Paddle {
    float x, y;
    float speed;
    int width, height;
    Color color;

    Rectangle GetRectangle() {
        return Rectangle { x - width / 2, y - height / 2, 10, 100 };
    }

    void DrawPaddle() {
        DrawRectangleRec(GetRectangle(), color);
    }
};

int main() {

    InitWindow(800, 600, "Pong");
    SetWindowState(FLAG_VSYNC_HINT);

    Ball ball;
    ball.x = GetScreenWidth() / 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.radius = 5;
    ball.color = WHITE;
    ball.speedX = 300;
    ball.speedY = 300;


    Paddle leftPaddle;
    leftPaddle.x = 50;
    leftPaddle.y = GetScreenHeight() / 2;
    leftPaddle.width = 10;
    leftPaddle.height = 100;
    leftPaddle.speed = 500;
    leftPaddle.color = WHITE;

    Paddle rightPaddle;
    rightPaddle.x = GetScreenWidth() - 50;
    rightPaddle.y = GetScreenHeight() / 2;
    rightPaddle.width = 10;
    rightPaddle.height = 100;
    rightPaddle.speed = 500;
    rightPaddle.color = WHITE;

    const char* winnerText = nullptr;

    while(!WindowShouldClose()) {

        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        if(ball.y < 0) {
            ball.y = 0;
            ball.speedY = -ball.speedY;
        }
        if(ball.y >= GetScreenHeight()) {
            ball.y = GetScreenHeight();
            ball.speedY = -ball.speedY;
        }

        if(rightPaddle.y >= GetScreenHeight()) {
            rightPaddle.y = 0;
        } else if (rightPaddle.y <= 0) {
            rightPaddle.y = GetScreenHeight();
        }

        if(leftPaddle.y >= GetScreenHeight()) {
            leftPaddle.y = 0;
        } else if (leftPaddle.y <= 0) {
            leftPaddle.y = GetScreenHeight();
        }
/* bounces ball off of wall behind paddle
        if(ball.x < 0) {
            ball.x = 0;
            ball.speedX = -ball.speedX;
        }
        if(ball.x >= GetScreenWidth()) {
            ball.x = GetScreenWidth();
            ball.speedX = -ball.speedX;
        }
*/
        if(IsKeyDown(KEY_W)) {
            leftPaddle.y -= leftPaddle.speed * GetFrameTime();
        }

        if(IsKeyDown(KEY_S)) {
            leftPaddle.y += leftPaddle.speed * GetFrameTime();
        }
/* remove to add second player
        if(IsKeyDown(KEY_UP)) {
            rightPaddle.y -= rightPaddle.speed * GetFrameTime();
        }

        if(IsKeyDown(KEY_DOWN)) {
            rightPaddle.y += rightPaddle.speed * GetFrameTime();
        }
*/
        // basic AI
        if(!winnerText) {
            rightPaddle.y = rightPaddle.y + ball.speedY * GetFrameTime();
        }

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, leftPaddle.GetRectangle())) {
            if(ball.speedX < 0) {
                ball.speedX = ball.speedX * -1.02;
                ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX;
            }
        }

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, rightPaddle.GetRectangle())) {
            if(ball.speedX > 0) {
                ball.speedX = ball.speedX * -1.02;
                ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * -ball.speedX;
            }
        }

        if(ball.x < 0) {
            winnerText = "AI wins!";
        }
        if(ball.x > GetScreenWidth()) {
            winnerText = "Player wins!";
        }

        if(winnerText && IsKeyPressed(KEY_SPACE)) {
            ball.x = GetScreenWidth() / 2;
            ball.y = GetScreenHeight() / 2;
            ball.speedX = 300;
            ball.speedY = 300;
            winnerText = nullptr;
            leftPaddle.x = 50;
            leftPaddle.y = GetScreenHeight() / 2;
            rightPaddle.x = GetScreenWidth() - 50;
            rightPaddle.y = GetScreenHeight() / 2;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            
            ball.DrawBall();

            leftPaddle.DrawPaddle(); // left rectangle
            rightPaddle.DrawPaddle(); // right rectangle

            if(winnerText) {
                int textWidth = MeasureText(winnerText, 60);
                DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, YELLOW);
            }

            DrawFPS(10, 10); // x, y. Origin is at top left corner
        EndDrawing();
    }


    CloseWindow();

    return 0;
}
