#include <stdio.h>

char args[4] = {0, 0, 0, 0};

void print(int num)
{
    char buffer[5];
    for (int i = 0; i < sizeof(args); i++)
        switch (args[i])
        {
        case 'b':
            for (int j = 7; j >= 0; j--)
                putchar((num & (1 << j)) == (1 << j) ? '1' : '0');
            putchar(' ');
            break;
        case 'o':
            snprintf(buffer, sizeof(buffer), "% 4o", num);
            for (int j = sizeof(buffer); j >= 0; j--)
                if (buffer[j] == ' ')
                {
                    buffer[j] = '0';
                    j = 0;
                }
            printf("%s ", buffer);
            break;
        case 'd':
            printf("% 3u ", num);
            break;
        case 'h':
            snprintf(buffer, sizeof(buffer), "% 4X", num);
            for (int j = sizeof(buffer); j >= 0; j--)
                if (buffer[j] == ' ')
                {
                    buffer[j] = 'x';
                    j = 0;
                }
            for (int j = sizeof(buffer); j >= 0; j--)
                if (buffer[j] == ' ')
                {
                    buffer[j] = '0';
                    j = 0;
                }
            printf("%s ", buffer);
            break;
        }
    printf("- \e[%dmThis is the test text!\e[0m\n", num);
}

void addarg(char c)
{
    if (c == 'x')
        c = 'h';
    for (int i = 0; i < sizeof(args); i++)
        if (args[i] == c)
            return;
    for (int i = 0; i < sizeof(args); i++)
        if (args[i] == '\0')
        {
            args[i] = c;
            return;
        }
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        char c;
        int j = 0;
        while ((c = argv[i][j++]) != '\0')
        {
            c |= 32;
            if (c == 'b' || c == 'o' || c == 'd' || c == 'h' || c == 'x')
                addarg(c);
        }
    }

    if (*args == '\0')
        *args = 'd';
    int code = 0;

    while (code <= 9)
        print(code++);

    code = 30;
    while (code <= 37)
        print(code++);

    code = 40;
    while (code <= 47)
        print(code++);

    print(code = 52);

    code = 90;
    while (code <= 97)
        print(code++);

    code = 100;
    while (code <= 107)
        print(code++);

    return 0;
}
