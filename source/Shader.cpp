#pragma  once 
#include "Shader.h"

Shader::Shader(const char* vertexsource_path, const char* fragmentsource_path)
{
	//ע��ifstream��ofstream������  ifstream��Ӳ���ļ����ڴ棬Ҳ���Ǵ��ļ��ж��ļ����ڴ��У�
	//��ofstream�ǽ��ļ���������ļ��У��Ǵ��ڴ浽Ӳ���ļ���һ�ֹ��̣����忴���ͣ�http://blog.csdn.net/augusdi/article/details/8865378
	
	ifstream vertexShaderFile, fragmentShaderFile;
	vertexShaderFile.open(vertexsource_path);
	fragmentShaderFile.open(fragmentsource_path);
	stringstream str_vertexsource, str_fragmentsource;
	str_vertexsource << vertexShaderFile.rdbuf();
	str_fragmentsource << fragmentShaderFile.rdbuf();

	//���ַ�����ת�����ַ���
	string vertexcode = str_vertexsource.str();
	string framentcode = str_fragmentsource.str();
	const char* char_vertexcode = vertexcode.c_str();
	const char* char_fragmentcode = framentcode.c_str();

	//���������붥����ɫ��
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &char_vertexcode, nullptr);
	glCompileShader(vertexShader);

	//��鶥����ɫ��������Ϣ������ִ������ӡ����
	GLint vertex_success;
	char vertex_info[1024];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertex_success);
	if (!vertex_success)
	{
		//��ȡ������Ϣ
		glGetShaderInfoLog(vertexShader, 1024, nullptr, vertex_info);
		cout << "������ɫ�����󣬴�����Ϣ�� " << vertex_info << endl;
	}


	//����������Ƭ����ɫ��
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &char_fragmentcode, nullptr);
	glCompileShader(fragmentShader);

	//���Ƭ����ɫ�������д��������������Ϣ
	GLint fragment_success;
	char  fragment_info[1024];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragment_success);
    if (!fragment_success)
    {
		glGetShaderInfoLog(fragmentShader, 1024, nullptr, fragment_info);
		cout << "Ƭ����ɫ�����󣬴�����ϢΪ�� " << fragment_info << endl;
    }
	
	//������ɫ�����򣬹���������ɫ�������Ӹ�����ɫ��
	ShaderProgram = glCreateProgram();
	glAttachShader(ShaderProgram, vertexShader);
	glAttachShader(ShaderProgram, fragmentShader);
	glLinkProgram(ShaderProgram);

	//���������ɫ�������Ƿ��ִ������д��������������Ϣ
	GLint ShaderProgram_success;
	char ShaderProgram_info[1024];
	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &ShaderProgram_success);
	if (!ShaderProgram_success)
	{
		glGetProgramInfoLog(ShaderProgram, 1024,nullptr,ShaderProgram_info);
	}
	//ɾ���Ѿ��󶨵���ɫ��
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


void Shader::ShaderProgramUse()
{
	glUseProgram(ShaderProgram);
}

Shader::~Shader()
{


}