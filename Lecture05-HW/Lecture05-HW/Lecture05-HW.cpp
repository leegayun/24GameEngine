#include <iostream>
#include <GLFW/glfw3.h>
#pragma comment(lib, "opengl32.lib")
float moveFactor = 0.0f;
float scaleFactor = 1.0f;
bool leftMouseDown = false;
bool rightMouseDown = false;
bool dragging = false;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error : " << description << std::endl;
}
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
        {
            leftMouseDown = true;
            dragging = false;
            glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
        }
        else if (action == GLFW_RELEASE)
        {
            leftMouseDown = false;
            dragging = false;
            glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_FALSE);
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            rightMouseDown = true;
            dragging = false;
            glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
        }
        else if (action == GLFW_RELEASE)
        {
            rightMouseDown = false;
            dragging = false;
            glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_FALSE);
        }
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (rightMouseDown || leftMouseDown)
    {
        dragging = true;
    }
}

int render()
{
    glBegin(GL_TRIANGLES);

    glVertex2f((0.0f + moveFactor)*scaleFactor,0.3f*scaleFactor);
    glVertex2f((0.1f + moveFactor)* scaleFactor, -0.1f * scaleFactor);
    glVertex2f((-0.2f + moveFactor) * scaleFactor, -0.3f * scaleFactor);

    glVertex2f((0.0f + moveFactor)*scaleFactor,0.3f* scaleFactor);
    glVertex2f((0.2f + moveFactor)*scaleFactor,-0.3f* scaleFactor);
    glVertex2f((-0.1f + moveFactor) * scaleFactor, -0.1f * scaleFactor);

    glVertex2f((0.2f + moveFactor) * scaleFactor, 0.1f * scaleFactor);
    glVertex2f((-0.0f + moveFactor) * scaleFactor, -0.1f * scaleFactor);
    glVertex2f((-0.2f + moveFactor) * scaleFactor, 0.1f * scaleFactor);
    glEnd();
    if (leftMouseDown && dragging)
    {
        moveFactor += 0.0001f;
        scaleFactor -= 0.001f;
    }
    else if (rightMouseDown && dragging)
    {
        scaleFactor += 0.001f;
    }


    return 0;
}

int main()
{

    /* glfw 라이브러리 초기화 */
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}