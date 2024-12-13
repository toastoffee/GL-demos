/**
  ******************************************************************************
  * @file           : tgl_window.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/12/13
  ******************************************************************************
  */

#include <glad/glad.h>

#include <imgui/backends/imgui_impl_opengl3.h>
#include <imgui/backends/imgui_impl_glfw.h>

#include <iostream>

#include "tgl_window.hpp"

bool tgl::Window::isGlfwInited = false;

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

tgl::Window::Window(int width, int height)
:   m_wndWidth(width), m_wndHeight(height),
    m_clearColor(0.f, 0.f, 0.f, 1.f),
    m_wnd(nullptr) { }

tgl::Window *tgl::Window::createWindow(int width, int height, const char *title) {

    if(!isGlfwInited) {
        isGlfwInited = initGlfw();
        assert(isGlfwInited && "ERROR::TGL_Window::GLFW::INITIALIZATION_FAILED");
    }

    auto *wnd = new Window(width, height);
    wnd->m_wnd = glfwCreateWindow(width, height, title, nullptr, nullptr);
    assert(wnd->m_wnd != nullptr && "ERROR::TGL_Window::GLFW::CREATE_WINDOW_FAILED");

    initGlfwWindow(wnd->m_wnd);


    return wnd;
}

// init glfw and set hints
bool tgl::Window::initGlfw() {

    glfwSetErrorCallback(glfw_error_callback);

    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only

#if defined(__APPLE__)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#endif

    return true;
}

GLFWwindow *tgl::Window::initGlfwWindow(GLFWwindow *wnd) {

    const char* glsl_version = "#version 410";

    glfwMakeContextCurrent(wnd);
    glfwSwapInterval(1);

    // GLAD加载系统相关的OpenGL函数指针地址
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // GLAD加载失败报错
        std::cout << "ERROR::TGL_Window::GLAD::INITIALIZATION_FAILED" << std::endl;
    }

    // set up ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    // setup imGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(wnd, true);
#ifdef __EMSCRIPTEN__
    ImGui_ImplGlfw_InstallEmscriptenCallbacks(window, "#canvas");
#endif
    ImGui_ImplOpenGL3_Init(glsl_version);

    return wnd;
}


