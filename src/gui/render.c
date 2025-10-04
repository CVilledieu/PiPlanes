#include "render.h"

WinCtx* create_window(void){
    if(!glfwInit()){
        glfwTerminate();
        return NULL;
    }
    WinCtx* ctx = malloc(sizeof(WinCtx));

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    ctx->window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, "Vulkan", NULL, NULL);
    if(!ctx->window){
        free(ctx);
        glfwTerminate();
        return NULL;
    }
    ctx->extension_count = 0;
    vkEnmerateateInstanceExtensionProperties(NULL, &ctx->extension_count, NULL);

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