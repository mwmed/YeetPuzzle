#include "base_window.h"

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


bool base_window::create()
{
    bool result = true;
    m_class = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, m_module, NULL, NULL, NULL, NULL, m_classtext.c_str(), NULL };
    ::RegisterClassEx(&m_class);

    m_window = CreateWindow(m_class.lpszClassName, m_windowtext.c_str(), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, m_class.hInstance, NULL);
    m_d3dbase = new base_d3d(m_window);

    std::cout << m_window << std::endl;

    if (!m_d3dbase->create_device()) {
        m_d3dbase->cleanup_device();
        result = false;
    }
    else {
        ::ShowWindow(m_window, SW_SHOWDEFAULT);
        ::UpdateWindow(m_window);
    }

    return result;
}

HWND base_window::get_window()
{
    return m_window;
}

base_d3d* base_window::get_d3dbase()
{
    return m_d3dbase;
}


LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}