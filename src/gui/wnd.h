#ifndef WND_H
#define WND_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <stdio.h>

#define MAX_TITLE_LENGTH 30
#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

typedef struct {
    int height;
    int width;
    int extension_count;
    char title[MAX_TITLE_LENGTH];
    GLFWwindow* window;
} WinCtx;


WinCtx* create_WinCtx(void);
void destroy_window(WinCtx* win_ctx);



#endif