#pragma once

#include <GLFW/glfw3.h>

using glfw_window = GLFWwindow;
using glfw_monitor = GLFWmonitor;

#define glfw_init glfwInit
#define glfw_create_window glfwCreateWindow
#define glfw_make_context_current glfwMakeContextCurrent
#define glfw_set_window_user_pointer glfwSetWindowUserPointer
#define glfw_destroy_window glfwDestroyWindow
#define glfw_poll_events glfwPollEvents
#define glfw_swap_buffers glfwSwapBuffers
#define glfw_swap_interval glfwSwapInterval