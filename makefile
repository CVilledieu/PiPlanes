# Makefile for building a Vulkan application
CC = gcc

APP = vulkan_app.exe
OUT_DIR = build

CFLAGS = -Wall -Wextra -Werror -g -std=c99

VULKAN_SDK_PATH = C:/VulkanSDK/1.4.321.1

#includes
INCLUDE_VULKAN = -I./include -I$(VULKAN_SDK_PATH)/Include
INCLUDE_PROJECT = -I./include

INCLUDE = $(INCLUDE_VULKAN) $(INCLUDE_PROJECT)

#libraries
LIB_VULKAN = -L$(VULKAN_SDK_PATH)/Lib
LIB_PROJECT = -L./lib

LIB_DIR = $(LIB_VULKAN) $(LIB_PROJECT)
LIBS = -lvulkan-1 -lglfw3 -lvulkan -lgdi32 -luser32 -lkernel32

LDFLAGS = $(LIB_DIR) $(LIBS)

#source files
SRC_DIR = ./src
SRC = $(shell find $(SRC_DIR) -name '*.c')

#shader files
SHADE_OUT_DIR = $(OUT_DIR)/shaders
SHADE_SRC = $(wildcard ./shaders/*.frag ./shaders/*.vert)


$(APP): main.o app.o window.o renderer.o device.o swapchain.o
	$(CC) $^ -o $@ $(LDFLAGS)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)
	mkdir -p $(SHADE_OUT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@