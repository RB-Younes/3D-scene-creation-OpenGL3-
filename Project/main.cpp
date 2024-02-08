#include <glad.h>
#include <GLFW/glfw3.h>
#include <windows.h>
#include <mmstream.h>
#include <iostream>
#include <string>
#include <shader.hpp>
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <objload.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#pragma comment(lib, "irrKlang.lib")


using namespace std;
GLuint VAO;
GLuint VBO;
GLuint VAO1;
GLuint VBO1;
GLuint VAO2;
GLuint VBO2;
GLuint VAO3;
GLuint VBO3;
GLuint VAO4;
GLuint VBO4;
GLuint VAO5;
GLuint VBO5;
GLuint VBOColor;

GLuint VAO6;
GLuint VBO6;
GLuint VBOColor1;

GLuint VAO7;
GLuint VBO7;
GLuint VBOColor2;

GLuint VAO8;
GLuint VBO8;
GLuint VBOColor3;

GLuint VAO9;
GLuint VBO9;
GLuint VBOColor4;

GLuint IBO;
GLuint TextureID;
using namespace glm;
double Xpos, Ypos ;
mat4 Model;

//vec3 lightColor(1.0f ,0.89f , 0.51f) ;
//vec3 lightColor(0.89f, 0.66f, 0.53f) ;
vec3 lightColor(0.3f, 0.3f, 0.3f);
//vec3 lightColor(0.99f, 0.72f, 0.07f);

std::string textemp="textures/sun 1.jpg";
std::string texsky="textures/sky2.jpg";

vec3 lightPos(0.0f, 0.0f ,-19.0f);


mat4 Projection;


std::vector<vec3> position;
std::vector<vec2> texture;
std::vector<vec3> normals;

std::vector<vec3> position1;
std::vector<vec2> texture1;
std::vector<vec3> normals1;

std::vector<vec3> position2;
std::vector<vec2> texture2;
std::vector<vec3> normals2;

std::vector<vec3> position3;
std::vector<vec2> texture3;
std::vector<vec3> normals3;

std::vector<vec3> position4;
std::vector<vec2> texture4;
std::vector<vec3> normals4;
struct STRVertex
{
 vec3 position;
 vec3 couleur;
 vec2 texture;
};

void Resize(GLFWwindow* window, int width, int height)
{
glViewport(0, 0, width, height);
}

//une seule texture
unsigned int text;
void InitTexture(void)
{
glGenTextures(1, &text);
glBindTexture(GL_TEXTURE_2D, text);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load("textures/pyr.jpg", &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);

};



unsigned int text2;
void InitTexture2(void)
{
glGenTextures(1, &text2);
glBindTexture(GL_TEXTURE_2D, text2);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load("textures/Soil.jpg", &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);

};

unsigned int text3;
void InitTexture3(void)
{
glGenTextures(1, &text3);
glBindTexture(GL_TEXTURE_2D, text3);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load(texsky.c_str(), &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);
};

unsigned int text4;
void InitTexture4(void)
{
glGenTextures(1, &text4);
glBindTexture(GL_TEXTURE_2D, text4);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load("textures/plante.jpg", &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);
};


unsigned int text5;
void InitTexture5(void)
{
glGenTextures(1, &text5);
glBindTexture(GL_TEXTURE_2D, text5);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load("textures/palm1_uv_m2.bmp", &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);
};


unsigned int text6;
void InitTexture6(void)
{
glGenTextures(1, &text6);
glBindTexture(GL_TEXTURE_2D, text6);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load(textemp.c_str(), &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);


};


unsigned int text7;
void InitTexture7(void)
{
glGenTextures(1, &text7);
glBindTexture(GL_TEXTURE_2D, text7);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load("textures/sphinx.jpg", &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);

};

unsigned int text8;
void InitTexture8(void)
{
glGenTextures(1, &text8);
glBindTexture(GL_TEXTURE_2D, text8);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load("textures/camel.jpg", &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);

};



//MAIN-------------------------------------------------------------------------------------------------------
int main()
{
if (!glfwInit()) {
    printf("Could not initialize glfw.\n");
    return -1;
}

glfwWindowHint(GLFW_SAMPLES, 4);
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR , 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

GLFWwindow* window;
window = glfwCreateWindow(800, 620, "Projet GL", NULL, NULL);

if (!window)
{
    glfwTerminate();
return -1;
}

glfwMakeContextCurrent(window);

if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
{
 printf("Could not initialize GLAD");
return -1;
}
//audio
PlaySound(TEXT("audio/desert1.wav"),NULL,SND_ASYNC);

//LOADING MODELS
loadOBJ("model/Palm_01.obj", position, texture, normals);
loadOBJ("model/MY_PALM.obj", position1, texture1, normals1);
loadOBJ("model/sphere.obj", position2, texture2, normals2);
loadOBJ("model/sphinx.obj", position3, texture3, normals3);
loadOBJ("model/camel.obj", position4, texture4, normals4);

GLuint ShaderProgram;
ShaderProgram = LoadShaders( "shader/SimpleVertexShader.vertexshader",
"shader/SimpleFragmentShader.fragmentshader" );

STRVertex vertices[] = {

        vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, -1.0f),vec2(0.0f,0.0f),
         vec3(0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, -1.0f),vec2(1.0f,0.0f),
         vec3(0.0f, 0.5f, 0.0f), vec3(0.0f, 0.0f, -1.0f),vec2(0.5f,1.0f),

        vec3(-0.5f, -0.5f, 0.5f), vec3(0.0f, 0.0f, 1.0f),vec2(0.0f,0.0f),
        vec3(0.5f, -0.5f, 0.5f), vec3(0.0f, 0.0f, 1.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 0.5f, 0.0f), vec3(0.0f, 0.0f, 1.0f),vec2(0.5f,1.0f),

        vec3(-0.5f, -0.5f, -0.5f),vec3(-1.0f, 0.0f, 0.0f),vec2(0.0f,0.0f),
        vec3(-0.5f, -0.5f, 0.5f),vec3(-1.0f, 0.0f, 0.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 0.5f, 0.0f),vec3(-1.0f, 0.0f, 0.0f),vec2(0.5f,1.0f),

        vec3(0.5f, -0.5f, -0.5f),vec3(1.0f, 0.0f, 0.0f),vec2(0.0f,0.0f),
        vec3(0.5f, -0.5f, 0.5f),vec3(1.0f, 0.0f, 0.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 0.5f, 0.0f),vec3(1.0f, 0.0f, 0.0f),vec2(0.5f,1.0f),


         vec3(0.5f, -0.5f, -0.5f),vec3(0.0f, -1.0f, 0.0f),vec2(0.0f,0.0f),
         vec3(0.5f, -0.5f, 0.5f),vec3(0.0f, -1.0f, 0.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 0.5f, 0.0f),vec3(0.0f, -1.0f, 0.0f),vec2(0.5f,1.0f),

         vec3(-0.5f, -0.5f, 0.5f),vec3(0.0f, 1.0f, 0.0f),vec2(0.0f,0.0f),
         vec3(-0.5f, -0.5f, -0.5f),vec3(0.0f, 1.0f, 0.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 0.5f, 0.0f),vec3(0.0f, 1.0f, 0.0f),vec2(0.5f,1.0f),

};


STRVertex vertices2[] = {

        vec3(-1.0f, -1.0f, -1.0f), vec3(0.0f, 0.0f, -1.0f),vec2(0.0f,0.0f),
         vec3(1.0f, -1.0f, -1.0f), vec3(0.0f, 0.0f, -1.0f),vec2(1.0f,0.0f),
         vec3(0.0f, 1.0f, 0.0f), vec3(0.0f, 0.0f, -1.0f),vec2(0.5f,1.0f),

        vec3(-1.0f, -1.0f, 1.0f), vec3(0.0f, 0.0f, 1.0f),vec2(0.0f,0.0f),
        vec3(1.0f, -1.0f, 1.0f), vec3(0.0f, 0.0f, 1.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f),vec2(0.5f,1.0f),

        vec3(-1.0f, -1.0f, -1.0f),vec3(-1.0f, 0.0f, 0.0f),vec2(0.0f,0.0f),
        vec3(-1.0f, -1.0f, 1.0f),vec3(-1.0f, 0.0f, 0.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 1.0f, 0.0f),vec3(-1.0f, 0.0f, 0.0f),vec2(0.5f,1.0f),

        vec3(1.0f, -1.0f, -1.0f),vec3(1.0f, 0.0f, 0.0f),vec2(0.0f,0.0f),
        vec3(1.0f, -1.0f, 1.0f),vec3(1.0f, 0.0f, 0.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 1.0f, 0.0f),vec3(1.0f, 0.0f, 0.0f),vec2(0.5f,1.0f),


         vec3(1.0f, -1.0f, -1.0f),vec3(0.0f, -1.0f, 0.0f),vec2(0.0f,0.0f),
         vec3(1.0f, -1.0f, 1.0f),vec3(0.0f, -1.0f, 0.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 1.0f, 0.0f),vec3(0.0f, -1.0f, 0.0f),vec2(0.5f,1.0f),

         vec3(-1.0f, -1.0f, 1.0f),vec3(0.0f, 1.0f, 0.0f),vec2(0.0f,0.0f),
         vec3(-1.0f, -1.0f, -1.0f),vec3(0.0f, 1.0f, 0.0f),vec2(1.0f,0.0f),
        vec3(0.0f, 1.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f),vec2(0.5f,1.0f),
};

STRVertex vertices3[] = {
         vec3(1.0f, 0.0f,1.0f),vec3(0.0f, 1.0f, 0.0f),vec2(0.0f,0.0f),
         vec3(1.0f, 0.0f,-1.0f),vec3(0.0f, 1.0f, 0.0f),vec2(1.0f,0.0f),
         vec3(-1.0f, 0.0f,1.0f), vec3(0.0f, 1.0f, 0.0f),vec2(0.5f,1.0f),

         vec3(-1.0f, 0.0f, -1.0f), vec3(0.0f, 1.0f, 0.0f),vec2(0.0f,0.0f),
         vec3(1.0f, 0.0f, -1.0f), vec3(0.0f, 1.0f, 0.0f),vec2(1.0f,0.0f),
         vec3(-1.0f, 0.0f, 1.0f), vec3(0.0f, 1.0f, 0.0f),vec2(0.5f,1.0f),
};

STRVertex vertices4[] = {
         vec3(1.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f),vec2(0.0f,0.0f),
         vec3(-1.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f),vec2(1.0f,0.0f),
         vec3(1.0f, 1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f),vec2(0.5f,1.0f),

         vec3(-1.0f, 1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f),vec2(0.0f,0.0f),
         vec3(-1.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f),vec2(1.0f,0.0f),
         vec3(1.0f, 1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f),vec2(0.5f,1.0f),

};



glGenVertexArrays(1, &VAO);
//glGentextutes(GLuint n, GLuint *tab_texture) ;
glBindVertexArray(VAO);

glGenBuffers(1, &VBO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,position) );
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,couleur) );
glEnableVertexAttribArray(1);
glEnableVertexAttribArray(2);
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*) offsetof(STRVertex,texture) );

//vao1 vbo1
glGenVertexArrays(1, &VAO1);
glBindVertexArray(VAO1);

glGenBuffers(1, &VBO1);
glBindBuffer(GL_ARRAY_BUFFER, VBO1);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,position) );
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,couleur) );
glEnableVertexAttribArray(1);
glEnableVertexAttribArray(2);
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*) offsetof(STRVertex,texture) );


//vao2 vbo2
glGenVertexArrays(1, &VAO2);
glBindVertexArray(VAO2);

glGenBuffers(1, &VBO2);
glBindBuffer(GL_ARRAY_BUFFER, VBO2);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);


glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,position) );
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,couleur) );
glEnableVertexAttribArray(1);
glEnableVertexAttribArray(2);
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*) offsetof(STRVertex,texture) );

//vao3 vbo3
glGenVertexArrays(1, &VAO3);
glBindVertexArray(VAO3);

glGenBuffers(1, &VBO3);
glBindBuffer(GL_ARRAY_BUFFER, VBO3);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);


glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,position) );
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,couleur) );
glEnableVertexAttribArray(1);
glEnableVertexAttribArray(2);
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*) offsetof(STRVertex,texture) );

//vao4 vbo4
glGenVertexArrays(1, &VAO4);
glBindVertexArray(VAO4);

glGenBuffers(1, &VBO4);
glBindBuffer(GL_ARRAY_BUFFER, VBO4);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);


glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,position) );
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*)offsetof(STRVertex,couleur) );
glEnableVertexAttribArray(1);
glEnableVertexAttribArray(2);
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(STRVertex) , (void*) offsetof(STRVertex,texture) );

//vao5 vbo5 loaded object
glGenVertexArrays(1, &VAO5);
glBindVertexArray(VAO5);
glGenBuffers(1, &VBO5);
glBindBuffer(GL_ARRAY_BUFFER, VBO5);
glBufferData(GL_ARRAY_BUFFER, position.size() * sizeof(vec3), &position[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0 );

glGenBuffers(1, &VBOColor);
glBindBuffer(GL_ARRAY_BUFFER, VBOColor);
glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(vec3), &normals[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(1);
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,3 * sizeof(GLfloat), (void*)0 );

//vao6 vbo6 loaded object
glGenVertexArrays(1, &VAO6);
glBindVertexArray(VAO6);
glGenBuffers(1, &VBO6);
glBindBuffer(GL_ARRAY_BUFFER, VBO6);
glBufferData(GL_ARRAY_BUFFER, position1.size() * sizeof(vec3), &position1[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0 );

glGenBuffers(1, &VBOColor1);
glBindBuffer(GL_ARRAY_BUFFER, VBOColor1);
glBufferData(GL_ARRAY_BUFFER, normals1.size() * sizeof(vec3), &normals1[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(1);
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,3 * sizeof(GLfloat), (void*)0 );


//vao7 vbo7 loaded object
glGenVertexArrays(1, &VAO7);
glBindVertexArray(VAO7);
glGenBuffers(1, &VBO7);
glBindBuffer(GL_ARRAY_BUFFER, VBO7);
glBufferData(GL_ARRAY_BUFFER, position2.size() * sizeof(vec3), &position2[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0 );

glGenBuffers(1, &VBOColor2);
glBindBuffer(GL_ARRAY_BUFFER, VBOColor2);
glBufferData(GL_ARRAY_BUFFER, normals2.size() * sizeof(vec3), &normals2[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(1);
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,3 * sizeof(GLfloat), (void*)0 );



//vao8 vbo8 loaded object
glGenVertexArrays(1, &VAO8);
glBindVertexArray(VAO8);
glGenBuffers(1, &VBO8);
glBindBuffer(GL_ARRAY_BUFFER, VBO8);
glBufferData(GL_ARRAY_BUFFER, position3.size() * sizeof(vec3), &position3[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0 );

glGenBuffers(1, &VBOColor3);
glBindBuffer(GL_ARRAY_BUFFER, VBOColor3);
glBufferData(GL_ARRAY_BUFFER, normals3.size() * sizeof(vec3), &normals3[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(1);
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,3 * sizeof(GLfloat), (void*)0 );


//vao8 vbo8 loaded object
glGenVertexArrays(1, &VAO9);
glBindVertexArray(VAO9);
glGenBuffers(1, &VBO9);
glBindBuffer(GL_ARRAY_BUFFER, VBO9);
glBufferData(GL_ARRAY_BUFFER, position4.size() * sizeof(vec3), &position4[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0 );

glGenBuffers(1, &VBOColor3);
glBindBuffer(GL_ARRAY_BUFFER, VBOColor3);
glBufferData(GL_ARRAY_BUFFER, normals4.size() * sizeof(vec3), &normals4[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(1);
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,3 * sizeof(GLfloat), (void*)0 );

float rayon = 5.0;

vec3 camPos = vec3(0.0f, 2.0f, 18.0f);
vec3 camDirection = vec3(0.0f, 0.0f, 0.0f);
vec3 camUp = vec3(0.0f, 1.0f, 0.0f);
float camSpeed = 0.005f;


mat4 Projection = perspective(radians(50.0f), 4.0f / 3.0f, 1.0f, 200.0f);
mat4 View = lookAt(camPos,camDirection,camUp);



glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LESS);

InitTexture();
InitTexture2();
InitTexture3();
InitTexture4();
InitTexture5();
InitTexture6();
InitTexture7();
InitTexture8();

float x=0.0;
float y=0.005;



while (!glfwWindowShouldClose(window)){


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    glUseProgram(ShaderProgram);

    TextureID = glGetUniformLocation(ShaderProgram, "ourTexture");

    GLuint LightClrID = glGetUniformLocation(ShaderProgram, "lightColor");
    glUniform3fv(LightClrID, 1, &lightColor[0]);

    GLuint LightPosID = glGetUniformLocation(ShaderProgram, "lightPos");
    glUniform3fv(LightPosID, 1, &lightPos[0]);
    // interaction----------------------------------------------------------------
    if (glfwGetKey (window, GLFW_KEY_Z) == GLFW_PRESS)
    {
    lightColor = vec3(0.89f, 0.66f, 0.53f) ;
    textemp ="textures/sun 0.jpg";
    InitTexture6();
    texsky ="textures/sky.jpg";
    InitTexture3();
    }
    if(glfwGetKey (window, GLFW_KEY_X) == GLFW_PRESS)
    {
    lightColor = vec3(0.3f, 0.3f, 0.3f) ;
    textemp ="textures/sun 1.jpg";
    InitTexture6();
    texsky ="textures/sky2.jpg";
    InitTexture3();
    }



    //------------------------------------------------------------------------------


     if (glfwGetKey (window, GLFW_KEY_DOWN) == GLFW_PRESS)
    camPos += camSpeed *  vec3(0.0f, 0.0f, 1.0f);
    if (glfwGetKey (window, GLFW_KEY_UP) == GLFW_PRESS)
    camPos -= camSpeed *  vec3(0.0f, 0.0f, 1.0f);
    if (glfwGetKey (window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    camPos += camSpeed * vec3(1.0f, 0.0f, 0.0f);
    if (glfwGetKey (window, GLFW_KEY_LEFT) == GLFW_PRESS)
    camPos -= camSpeed * vec3(1.0f, 0.0f, 0.0f);
    if (glfwGetKey (window, GLFW_KEY_W) == GLFW_PRESS)
    camPos += camSpeed * vec3(0.0f, 1.0f, 0.0f);
    if (glfwGetKey (window, GLFW_KEY_S) == GLFW_PRESS)
    camPos -= camSpeed * vec3(0.0f, 1.0f, 0.0f);
    //up date the view
    View = lookAt(camPos,camDirection,camUp);

    glBindVertexArray(VAO);
    mat4 Model = mat4(1.0f);
    Model = translate(Model,vec3(-2.0f, -0.5f, 3.0f));
    mat4 MVP = Projection * View * Model;

    GLuint ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    GLuint MatrixID = glGetUniformLocation(ShaderProgram, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18);

    //-------------------------------------------------------------------------------------------------
    glBindVertexArray(VAO1);

    //up date the view
    Model = mat4(1.0f);
    Model = scale(Model,vec3(2.5f, 2.5f ,2.5f));
    Model = translate(Model,vec3(0.0f, 0.1f, 0.0f));
    MVP = Projection * View * Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18);

    //-------------------------------------------------------------------------------------------------
    glBindVertexArray(VAO2);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(3.0f, 0.0f, -2.5f));
    MVP = Projection * View * Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18);
    //GROUND-------------------------------------------------------------------------------------------------
    glBindVertexArray(VAO3);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = scale(Model,vec3(40.0f, 10.0f ,20.0f));
    Model = translate(Model,vec3(0.0f, -0.1f, 0.0f));
    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text2);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18);
  //SKY-------------------------------------------------------------------------------------------------
    glBindVertexArray(VAO4);
    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = scale(Model,vec3(40.0f, 20.0f ,10.0f));
    Model = translate(Model,vec3(0.0f, -0.05f, -2.0f));
    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);
    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text3);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18);
    //sky box----------------------------------------------------------------------
    glBindVertexArray(VAO4);
    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = scale(Model,vec3(40.0f, 20.0f ,10.0f));
    Model = translate(Model,vec3(0.0f, -0.05f, 2.0f));
    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);
    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text3);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18);


     glBindVertexArray(VAO4);
    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
     Model = rotate(Model,radians(90.0f),vec3(0.0f,1.0f,0.0f));
    Model = scale(Model,vec3(40.0f, 20.0f ,10.0f));
    Model = translate(Model,vec3(0.0f, -0.05f, 4.0f));
    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);
    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text3);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18);

     glBindVertexArray(VAO4);
    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
     Model = rotate(Model,radians(-90.0f),vec3(0.0f,1.0f,0.0f));
    Model = scale(Model,vec3(40.0f, 20.0f ,10.0f));
    Model = translate(Model,vec3(0.0f, -0.05f, 4.0f));
    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);
    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text3);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18);

 glBindVertexArray(VAO3);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = scale(Model,vec3(40.0f, 10.0f ,20.0f));
    Model = translate(Model,vec3(0.0f, 1.8f, 0.0f));
    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text3);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18);
//palm trees --------------------------------------------------------------------------------------------------
    glBindVertexArray(VAO5);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(0.0f, -1.0f, 5.0f));
    Model = scale(Model,vec3(0.05f, 0.05f ,0.05f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text4);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18561);

    glBindVertexArray(VAO5);
    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(5.0f, -1.0f, -3.0f));
    Model = scale(Model,vec3(0.03f, 0.03f ,0.03f));

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MVP = Projection * View *Model;

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text4);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18561);

    glBindVertexArray(VAO5);
    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(-7.0f, -1.0f, -3.0f));
    Model = scale(Model,vec3(0.04f, 0.04f ,0.04f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text4);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18561);


       glBindVertexArray(VAO5);
    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(7.0f, -1.0f, -2.0f));
    Model = scale(Model,vec3(0.04f, 0.04f ,0.04f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);


    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text4);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18561);

    glBindVertexArray(VAO5);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(-2.0f, -1.0f, -2.0f));
    Model = scale(Model,vec3(0.05f, 0.05f ,0.05f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text4);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 18561);

//PALM TREES--------------------------------------------------------------------------------------------------
    glBindVertexArray(VAO6);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(7.0f, -1.0f, 5.0f));
    Model = scale(Model,vec3(0.04f, 0.04f ,0.04f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text5);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 639);

     glBindVertexArray(VAO6);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(3.0f, -1.0f, -6.0f));
    Model = scale(Model,vec3(0.05f, 0.05f ,0.05f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text5);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 639);
     glBindVertexArray(VAO6);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(2.0f, -1.0f, -5.0f));
    Model = scale(Model,vec3(0.04f, 0.04f ,0.04f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text5);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 639);

     glBindVertexArray(VAO6);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(-2.0f, -1.0f, -4.0f));
    Model = scale(Model,vec3(0.04f, 0.04f ,0.04f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text5);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 639);

     glBindVertexArray(VAO6);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(-7.0f, -1.0f, 2.0f));
    Model = scale(Model,vec3(0.05f, 0.05f ,0.05f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text5);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 639);

     glBindVertexArray(VAO6);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(-6.0f, -1.0f, -5.0f));
    Model = scale(Model,vec3(0.03f, 0.03f ,0.03f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text5);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 639);

     glBindVertexArray(VAO6);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(-4.0f, -1.0f, 7.0f));
    Model = scale(Model,vec3(0.04f, 0.04f ,0.04f));

    MVP = Projection * View *Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text5);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 639);

//Sphinx--------------------------------------------------------------------------------------------------
    glBindVertexArray(VAO8);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    Model = translate(Model,vec3(-4.0f, -1.15f ,4.0f));
    Model = scale(Model,vec3(0.05f, 0.05f ,0.05f));

    MVP = Projection * View * Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text7);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 186336);


//SOLEIL--------------------------------------------------------------------------------------------------
    /*if(x <=230.0f){
        lightColor = vec3(0.89f, 0.66f, 0.53f);
    }
    if(x >=230.0f){
         lightColor = vec3(0.f, 0.1f, 0.1f);
    }
    if(x==360.0f){
            lightColor = vec3(0.89f, 0.66f, 0.53f);
            x=0.0f;
    }*/
    if(glfwGetKey (window, GLFW_KEY_I) == GLFW_PRESS){
            y=y+0.005f;
    }
    if(glfwGetKey (window, GLFW_KEY_K) == GLFW_PRESS && y >= 0.01f){
            y=y-0.005f;
    }
    glBindVertexArray(VAO7);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);
    x=x+y;
    Model = rotate(Model,radians(x),vec3(1.0f,0.0f,0.0f));
    Model = translate(Model,vec3(0.0f, 0.0f ,-20.0f));
    Model = scale(Model,vec3(1.0f, 1.0f ,1.0f));

    lightPos =  vec3 (Model * vec4(1.0f, 1.0f ,1.0f,1.0f));

    MVP = Projection * View * Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text6);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 2880);



//CAMEL--------------------------------------------------------------------------------------------------
    glBindVertexArray(VAO9);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);


    Model = translate(Model,vec3(1.0f, -0.8f ,3.0f));
    Model = scale(Model,vec3(0.2f, 0.2f ,0.2f));
    Model = rotate(Model,radians(-50.0f),vec3(0.0f,1.0f,0.0f));

    MVP = Projection * View * Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text8);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 2466);


    glBindVertexArray(VAO9);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);


    Model = translate(Model,vec3(1.0f, -0.8f ,4.0f));
    Model = scale(Model,vec3(0.2f, 0.2f ,0.2f));
    Model = rotate(Model,radians(-90.0f),vec3(0.0f,1.0f,0.0f));

    MVP = Projection * View * Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text7);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 2466);

     glBindVertexArray(VAO9);

    //up date the view
    View = lookAt(camPos,camDirection,camUp);
    Model = mat4(1.0f);


    Model = translate(Model,vec3(1.5f, -0.8f ,4.0f));
    Model = scale(Model,vec3(0.2f, 0.2f ,0.2f));
    Model = rotate(Model,radians(-120.0f),vec3(0.0f,1.0f,0.0f));

    MVP = Projection * View * Model;

    ModelID = glGetUniformLocation(ShaderProgram, "Model");
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &Model[0][0]);

    MatrixID = glGetUniformLocation(ShaderProgram, "MVP");

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text8);
    glUniform1i(TextureID, 0);
    glDrawArrays(GL_TRIANGLES, 0, 2466);




//--------------------------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();

}
glDeleteVertexArrays(1, &VAO);
glDeleteBuffers(1, &VBO);
glDeleteVertexArrays(1, &VAO1);
glDeleteBuffers(1, &VBO1);
glDeleteVertexArrays(1, &VAO2);
glDeleteBuffers(1, &VBO2);
glDeleteVertexArrays(1, &VAO3);
glDeleteBuffers(1, &VBO3);
glDeleteVertexArrays(1, &VAO4);
glDeleteBuffers(1, &VBO4);
glDeleteVertexArrays(1, &VAO5);
glDeleteBuffers(1, &VBO5);
glDeleteVertexArrays(1, &VAO6);
glDeleteBuffers(1, &VBO6);
glDeleteVertexArrays(1, &VAO7);
glDeleteBuffers(1, &VBO7);
glDeleteVertexArrays(1, &VAO8);
glDeleteBuffers(1, &VBO8);
glDeleteVertexArrays(1, &VAO9);
glDeleteBuffers(1, &VBO9);
glfwDestroyWindow(window);
glfwTerminate();
}
