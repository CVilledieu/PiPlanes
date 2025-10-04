#include "wnd.h"
#include <stdio.h>

static void resize_cb(GLFWwindow* window, int width, int height){
    WinCtx* ctx = (WinCtx*)glfwGetWindowUserPointer(window);
    ctx->width = width;
    ctx->height = height;
    glViewport(0, 0, width, height);
}

static void keypress_cb(GLFWwindow* window, int key, int scancode, int action, int mods){
    WinCtx* ctx = (WinCtx*)glfwGetWindowUserPointer(window);
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}

void create_window(WinCtx* ctx){
    if(!glfwInit()){
        printf("%s\n", "Failed to create GLFW window");
        glfwTerminate();
        return NULL;
    }
    WinCtx* ctx = malloc(sizeof(WinCtx));

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    

    ctx->window = glfwCreateWindow(ctx->width, ctx->height, ctx->title, NULL, NULL);
    glfwMakeContextCurrent(ctx->window);
    if(!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress)){
        printf("%s\n", "Failed to initialize GLAD");
        destroy_window(ctx);
        return NULL;
    }

    glViewPort(0, 0, ctx->width, ctx->height);
    glfwSetWindowUserPointer(ctx->window, ctx);
    glfwSetFramebufferSizeCallback(ctx->window, resize_cb);
    glfwSetKeyCallback(ctx->window, keypress_cb);
    return ctx;
}

WinCtx* create_WinCtx(){
    WinCtx* ctx = malloc(sizeof(WinCtx));
    ctx->window = NULL;
    ctx->width = DEFAULT_WIDTH;
    ctx->height = DEFAULT_HEIGHT;
    ctx->title[MAX_TITLE_LENGTH] = "Plane chaser";

    create_window(ctx);
    return ctx;
}


void destroy_window(WinCtx* ctx){
    if(ctx){
        if(ctx->window)
            glfwDestroyWindow(ctx->window);
        free(ctx);
    }
    glfwTerminate();
}