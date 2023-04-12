﻿// prac01.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
// 2023. 3. 11.
// Created by Soo Kyun Kim
#define _USE_MATH_DEFINES
<<<<<<< Updated upstream
<<<<<<< Updated upstream

#include <math.h>
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

#include "framework.h"
#include "prac01.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <math.h>


#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
//-----------------------------------------------------
double x = 2;
double y = 2;
double z = 2;
double xa = 0;
double ya = 0;
double za = 0;
double deg2rad(const float deg) {
    return deg * M_PI / 180;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream

//-----------------------------------------------------
=======
=======
>>>>>>> Stashed changes
//----------------------------
double deg2rad(const float deg) {
    return deg * M_PI / 180;
}

//----------------------------

<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
/////////////////////// sk
HDC hDeviceContext;								// current device context
HGLRC hRenderingContext;						// current rendering context

bool bSetupPixelFormat(HDC hdc);
void Resize(int width, int height);
void DrawScene(HDC MyDC);


//-----------------------------------------------------
GLfloat vertices[8][3] = {
    { -1.0f, -1.0f,  1.0f }, { -1.0f,  1.0f,  1.0f },
    {  1.0f,  1.0f,  1.0f }, {  1.0f, -1.0f,  1.0f },
    { -1.0f, -1.0f, -1.0f }, { -1.0f,  1.0f, -1.0f },
    {  1.0f,  1.0f, -1.0f }, {  1.0f, -1.0f, -1.0f } };
GLfloat colors[8][3] = {
    { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 1.0f },
    { 1.0f, 1.0f, 1.0f }, { 1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f },
    { 1.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } };

void Quad(int a, int b, int c, int d);
//-----------------------------------------------------


void Quad(int a, int b, int c, int d)
{
    glBegin(GL_QUADS);
    glColor3fv(colors[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glVertex3fv(vertices[d]);
    glEnd();

    return;
}

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PRAC01, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PRAC01));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PRAC01));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName =  MAKEINTRESOURCEW(IDC_PRAC01);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
<<<<<<< Updated upstream
<<<<<<< Updated upstream
       CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);
=======
       CW_USEDEFAULT, 0, 500, 500, nullptr, nullptr, hInstance, nullptr);
>>>>>>> Stashed changes
=======
       CW_USEDEFAULT, 0, 500, 500, nullptr, nullptr, hInstance, nullptr);
>>>>>>> Stashed changes

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    RECT clientRect;
    switch (message)
    {
    case WM_CREATE:
        // Initialize for the OpenGL rendering
        hDeviceContext = GetDC(hWnd);
        if (!bSetupPixelFormat(hDeviceContext)) {
            MessageBox(hWnd, "Error in setting up pixel format for OpenGL", "Error", MB_OK | MB_ICONERROR);
            DestroyWindow(hWnd);
        }
        hRenderingContext = wglCreateContext(hDeviceContext);
        wglMakeCurrent(hDeviceContext, hRenderingContext);
        break;

    case WM_SIZE:
        GetClientRect(hWnd, &clientRect);
        Resize(clientRect.right, clientRect.bottom);
        InvalidateRect(hWnd, NULL, false);

        break;

    case WM_KEYDOWN:
        if (wParam == VK_LEFT) {
            xa = xa + 15;
            za = za + 15;
            x = (cos(deg2rad(xa)) * 4);
            z = (sin(deg2rad(za)) * 4);
            
        }
        if (wParam == VK_RIGHT) {
            xa = xa - 15;
            za = za - 15;
            x = (cos(deg2rad(xa)) * 4);
            z = (sin(deg2rad(za)) * 4);
        }
        if (wParam == VK_DOWN) {
            ya = ya + 15;
            za = za + 15;
            z = (cos(deg2rad(za)) * 4);
            y = (sin(deg2rad(za)) * -4);
            
        
        }
        if (wParam == VK_UP) {
            y = y + 0.5;
        }
        InvalidateRect(hWnd, NULL, false);
        break;
        /*
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
        */
    case WM_PAINT:
        {
        DrawScene(hDeviceContext);
        ValidateRect(hWnd, NULL);
      
        /*
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
            */
        }
        break;
    case WM_DESTROY:
        // Destroy all about OpenGL
        if (hRenderingContext)
            wglDeleteContext(hRenderingContext);
        if (hDeviceContext)
            ReleaseDC(hWnd, hDeviceContext);

        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

bool bSetupPixelFormat(HDC hdc)
{
    PIXELFORMATDESCRIPTOR pfd;
    int pixelformat;

    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.dwLayerMask = PFD_MAIN_PLANE;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.cAccumBits = 0;
    pfd.cStencilBits = 0;

    if ((pixelformat = ChoosePixelFormat(hdc, &pfd)) == 0) {
        MessageBox(NULL, "ChoosePixelFormat() failed!!!", "Error", MB_OK | MB_ICONERROR);
        return false;
    }

    if (SetPixelFormat(hdc, pixelformat, &pfd) == false) {
        MessageBox(NULL, "SetPixelFormat() failed!!!", "Error", MB_OK | MB_ICONERROR);
        return false;
    }

    return true;
}

void Resize(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, width, height);

    if (width <= height)
<<<<<<< Updated upstream
<<<<<<< Updated upstream
        //gluOrtho2D(0, 500, 0, 500 * (GLfloat)width / (GLfloat)height);
        glFrustum(-2.0, 2.0, -2.0 * (GLfloat)height / (GLfloat)width, 2.0 * (GLfloat)height / (GLfloat)width, 1.0, 10.0);
=======
        gluOrtho2D(0, 500, 0, 500 * (GLfloat)width / (GLfloat)height);
        //glFrustum(-2.0, 2.0, -2.0 * (GLfloat)height / (GLfloat)width, 2.0 * (GLfloat)height / (GLfloat)width, 1.0, 10.0);
=======
        gluOrtho2D(0, 500, 0, 500 * (GLfloat)width / (GLfloat)height);
        //glFrustum(-2.0, 2.0, -2.0 * (GLfloat)height / (GLfloat)width, 2.0 * (GLfloat)height / (GLfloat)width, 1.0, 10.0);


    else
        gluOrtho2D(0, 500 * (GLfloat)width / (GLfloat)height, 0, 500);
        //glFrustum(-2.0 * (GLfloat)width / (GLfloat)height, 2.0 * (GLfloat)width / (GLfloat)height, -2.0, 2.0, 1.0, 10.0);
    return;
>>>>>>> Stashed changes


    else
        gluOrtho2D(0, 500 * (GLfloat)width / (GLfloat)height, 0, 500);
        //glFrustum(-2.0 * (GLfloat)width / (GLfloat)height, 2.0 * (GLfloat)width / (GLfloat)height, -2.0, 2.0, 1.0, 10.0);
    return;
>>>>>>> Stashed changes


    else
        //gluOrtho2D(0, 500 * (GLfloat)width / (GLfloat)height, 0, 500);
        glFrustum(-2.0 * (GLfloat)width / (GLfloat)height, 2.0 * (GLfloat)width / (GLfloat)height, -2.0, 2.0, 1.0, 10.0);
    return;

}

   
/*
* DrawScene : to draw a scene
*/
void DrawScene(HDC MyDC)
{
    glEnable(GL_DEPTH_TEST);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
<<<<<<< Updated upstream
    
    gluLookAt(x, y, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
=======

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    
    glVertex2f(cos(deg2rad(90)) * 100 + 250, sin(deg2rad(90)) * 100 + 250);
    glVertex2f(cos(deg2rad(234)) * 100 + 250, sin(deg2rad(234)) * 100 + 250);
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

    glVertex2f(cos(deg2rad(234)) * 100 + 250, sin(deg2rad(234)) * 100 + 250);
    glVertex2f(cos(deg2rad(378)) * 100 + 250, sin(deg2rad(378)) * 100 + 250);

    glVertex2f(cos(deg2rad(378)) * 100 + 250, sin(deg2rad(378)) * 100 + 250);
    glVertex2f(cos(deg2rad(162)) * 100 + 250, sin(deg2rad(162)) * 100 + 250);

    glVertex2f(cos(deg2rad(162)) * 100 + 250, sin(deg2rad(162)) * 100 + 250);
    glVertex2f(cos(deg2rad(306)) * 100 + 250, sin(deg2rad(306)) * 100 + 250);

    glVertex2f(cos(deg2rad(306)) * 100 + 250, sin(deg2rad(306)) * 100 + 250);
    glVertex2f(cos(deg2rad(90)) * 100 + 250, sin(deg2rad(90)) * 100 + 250);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    glVertex2f(cos(deg2rad(90)) * 100 + 250, sin(deg2rad(90)) * 100 + 250);
    glEnd();

   // glVertex2f(cos(deg2rad(90)) * 100 + 250, sin(deg2rad(90)) * 100 + 250);
   // glVertex2f(cos(deg2rad(162)) * 100 + 250, sin(deg2rad(162)) * 100 + 250);
   // glVertex2f(cos(deg2rad(234)) * 100 + 250, sin(deg2rad(234)) * 100 + 250);
   // glVertex2f(cos(deg2rad(306)) * 100 + 250, sin(deg2rad(306)) * 100 + 250);
   // glVertex2f(cos(deg2rad(378)) * 100 + 250, sin(deg2rad(378)) * 100 + 250);
<<<<<<< Updated upstream

    Quad(0, 3, 2, 1);
    Quad(1, 2, 6, 5);
    Quad(2, 3, 7, 6);
    Quad(3, 0, 4, 7);
    Quad(4, 5, 6, 7);
    Quad(5, 4, 0, 1);
=======
>>>>>>> Stashed changes


    SwapBuffers(MyDC);

  

    return;
}