#version 330 core
in vec2 texcordition;
in vec4 color;
out vec4 outcolor;
//uniform������ȫ�ֱ���������ֱ����ƬԪ��ɫ����ʹ�ã�������ͨ��������ɫ����
//��������ͨ��������ɫ�����䣬��û�������Ҫ��
uniform vec4 ourcolor;
uniform sampler2D  texture1;
uniform sampler2D  texture2; 

void main()
{
   //outcolor=texture(texture2,texcordition) *ourcolor;
   outcolor=mix(texture(texture1, texcordition), texture(texture2, texcordition), 0.5);

}

