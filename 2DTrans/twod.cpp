//
//  twod.cpp
//  2DTrans
//
//  Created by shivkanth on 29/08/13.
//  Copyright (c) 2013 shivkanth. All rights reserved.
//

#include<GLUT/glut.h>
#include <iostream>
using namespace std;
void myInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-640.0,640.0,-480.0,480.0);
    glBegin(GL_POINTS);
    // glVertex2d(-100.0, 0.0);
    //glVertex2d(0.0,-480.0 );
    glEnd();
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_LINES);
    glVertex2d(0.0, 480.0);
    glVertex2d(0.0, -480.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(640.0, 0.0);
    glVertex2d(-640.0, 0.0);
    glEnd();
    
    int tx,ty;
    std::cout<<"enter the x and y translation values";
    cin>>tx>>ty;
    glBegin(GL_QUADS);
    glVertex2d(100,100);
    glVertex2d(100,200);
    glVertex2d(200,200);
    glVertex2d(200,100);
    glEnd();
    
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,2.0f,0.0f);
    
    glBegin(GL_QUADS);
    glVertex2d(100+tx,100+ty);
    glVertex2d(100+tx,200+ty);
    glVertex2d(200+tx,200+ty);
    glVertex2d(200+tx,100+ty);
    glEnd();
    
    glFlush();
}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("First Exercise");
    glutDisplayFunc(myDisplay);
    myInit();
    //glutDisplayFunc(myDisplay1);
    glutMainLoop();
    return 1;
}

