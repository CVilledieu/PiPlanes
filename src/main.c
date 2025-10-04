#include "gui/render.h"


int main(){
    WinCtx* ctx = init_window();
    

    while(!glfwWindowShouldClose(ctx->window)){
        glfwPollEvents();
    }

    destroy_window(ctx);
    return 0;
}

