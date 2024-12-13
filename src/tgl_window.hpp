/**
  ******************************************************************************
  * @file           : tgl_window.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/12/13
  ******************************************************************************
  */



#ifndef GL_DEMOS_TGL_WINDOW_HPP
#define GL_DEMOS_TGL_WINDOW_HPP

#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

namespace tgl {

    class Window {

    private:
        static bool initGlfw();
        static GLFWwindow* initGlfwWindow(GLFWwindow* wnd);

        Window(int width, int height);

    public:
        static Window* createWindow(int width, int height, const char* title);


    private:
        GLFWwindow * m_wnd;
        ImVec4 m_clearColor;
        int m_wndWidth, m_wndHeight;
        static bool isGlfwInited;
    };

}



#endif //GL_DEMOS_TGL_WINDOW_HPP
