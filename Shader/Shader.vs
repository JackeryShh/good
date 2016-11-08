#version 330 core

layout(location = 0) in vec3 vertexposition;
//vertexcolor�Ƕ������ɫ��һ����Ĭ�ϵģ���û�в��ʻ�������״̬�µ���ɫ��
//�����������ɫ�Ļ��������ɫ��û���ڵı�Ҫ����������Ҫ��Ϊ��ģ����ɫ����ϣ�
//�ڱ���������˳��Ϊ�������꣬������ɫ�ȣ���ģ���У�
layout(location = 1) in vec3 vertexcolor;//������ɫ
layout(location = 2) in vec2 texturecord;//�������� 
out vec4 color;
uniform vec4 move;
//uniform vec4 ourcolor;
out vec2 texcordition;

uniform mat4 translate;

void main()
{
gl_Position=translate*vec4(vertexposition,1.0);
color=vec4(vertexcolor,1.0);//ourcolor;
texcordition=vec2(texturecord.x,1.0-texturecord.y);
}
