#include "render.h"

WinCtx* create_window(void){
    if(!glfwInit()){
        glfwTerminate();
        return NULL;
    }
    WinCtx* ctx = malloc(sizeof(WinCtx));

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    

    ctx->window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, "Vulkan", NULL, NULL);
    glfwMakeContextCurrent(ctx->window);
    if(!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress)){
        destroy_window(ctx);
        return NULL;
    }


    if(!ctx->window){
        free(ctx);
        glfwTerminate();
        return NULL;
    }
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