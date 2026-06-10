#include <stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = ' ';
        }
    }
}

void displayCanvas()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
            printf("_");
        printf("\n");

        for(j = 0; j < COLS; j++)
            printf("%c", canvas[i][j]);
        printf("\n");
    }

    for(j = 0; j < COLS; j++)
        printf("_");
    printf("\n");
}

void drawLine(int row, int col, int length)
{
    int i;

    if(row < 0 || row >= ROWS)
        return;

    for(i = 0; i < length && col + i < COLS; i++)
    {
        if(col + i >= 0)
            canvas[row][col + i] = '*';
    }
}

void drawRectangle(int row, int col, int height, int width)
{
    int i;

    if(row < 0 || col < 0 || row + height > ROWS || col + width > COLS)
        return;

    for(i = 0; i < width; i++)
    {
        canvas[row][col + i] = '#';
        canvas[row + height - 1][col + i] = '#';
    }

    for(i = 0; i < height; i++)
    {
        canvas[row + i][col] = '#';
        canvas[row + i][col + width - 1] = '#';
    }
}

void drawTriangle(int row, int col, int height)
{
    int i, j;

    if(row < 0 || col < 0 || row + height > ROWS)
        return;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j <= i && col + j < COLS; j++)
        {
            canvas[row + i][col + j] = '^';
        }
    }
}

void drawCircle(int centerRow, int centerCol, int radius)
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            int dx = i - centerRow;
            int dy = j - centerCol;

            if(dx * dx + dy * dy <= radius * radius)
            {
                canvas[i][j] = 'O';
            }
        }
    }
}

void deleteArea(int row, int col, int height, int width)
{
    int i, j;

    for(i = row; i < row + height && i < ROWS; i++)
    {
        for(j = col; j < col + width && j < COLS; j++)
        {
            if(i >= 0 && j >= 0)
                canvas[i][j] = ' ';
        }
    }
}

int main()
{
    int choice;

    initCanvas();

    while(1)
    {
        printf("\n===== ACP 2D Graphics Editor =====\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Delete Area\n");
        printf("5. Draw Circle\n");
        printf("6. Display Canvas\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            int r, c, len;

            initCanvas();

            printf("Row Col Length: ");
            scanf("%d %d %d", &r, &c, &len);

            drawLine(r, c, len);
            displayCanvas();
        }
        else if(choice == 2)
        {
            int r, c, h, w;

            initCanvas();

            printf("Row Col Height Width: ");
            scanf("%d %d %d %d", &r, &c, &h, &w);

            drawRectangle(r, c, h, w);
            displayCanvas();
        }
        else if(choice == 3)
        {
            int r, c, h;

            initCanvas();

            printf("Row Col Height: ");
            scanf("%d %d %d", &r, &c, &h);

            drawTriangle(r, c, h);
            displayCanvas();
        }
        else if(choice == 4)
        {
            int r, c, h, w;

            printf("Row Col Height Width: ");
            scanf("%d %d %d %d", &r, &c, &h, &w);

            deleteArea(r, c, h, w);
            displayCanvas();
        }
        else if(choice == 5)
        {
            int r, c, radius;

            initCanvas();

            printf("CenterRow CenterCol Radius: ");
            scanf("%d %d %d", &r, &c, &radius);

            drawCircle(r, c, radius);
            displayCanvas();
        }
        else if(choice == 6)
        {
            displayCanvas();
        }
        else if(choice == 7)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
