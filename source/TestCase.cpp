#include<stdio.h>
#include<string.h>
#include<json.h>
#include<io.h>
#include<fstream>
#include <iostream>

using namespace std;

//从文件中读取JSON
void ReadJsonFile() {
	ifstream ifs;
	string jsonfile = "config/config.json";
	ifs.open(jsonfile.c_str());
	Json::Reader reader;
	Json::Value root;
	if (!reader.parse(ifs, root, false)) {
		printf("%s文件都取错误!!!\n", jsonfile.c_str());
		return;
	}
	string appId_face = root["appId_face"].asString();
	string appSecrect = root["appSecrect"].asString();
	string rsFacedbPath = root["rsFacedbPath"].asString();
	string faceTestResultPath = root["faceTestResultPath"].asString();
	string faceFeaturePath = root["faceFeaturePath"].asString();
	int rsTestKey1 = root["faceTestKey"]["detect"].asInt();
	int rsTestKey2 = root["faceTestKey"]["recognition"].asInt();
	int rsTestKey3 = root["faceTestKey"]["track"].asInt();
	int rsTestKey4 = root["faceTestKey"]["livenssdete"].asInt();
	int rsTestKey5 = root["faceTestKey"]["attributedete"].asInt();
	int rsTestKey6 = root["faceTestKey"]["quality"].asInt();

	//读取数组信息
	
	for (int i = 0; i < root["achievement"].size(); i++)
	{
		string ach = root["achievement"][i].asString();
	}

	ifs.close();
}
//从字符串中读取JSON
int toStringRead()
{
	//字符串
	const char* str =
		"{\"praenomen\":\"Gaius\",\"nomen\":\"Julius\",\"cognomen\":\"Caezar\","
		"\"born\":-100,\"died\":-44}";

	Json::Reader reader;
	Json::Value root;

	//从字符串中读取数据
	if (reader.parse(str, root))
	{
		string praenomen = root["praenomen"].asString();
		string nomen = root["nomen"].asString();
		string cognomen = root["cognomen"].asString();
		int born = root["born"].asInt();
		int died = root["died"].asInt();

		cout << praenomen + " " + nomen + " " + cognomen
			<< " was born in year " << born
			<< ", died in year " << died << endl;
	}

	return 0;
}

//将信息保存为JSON格式
int saveJsonFile()
{
	//根节点
	Json::Value root;

	//根节点属性
	root["name"] = Json::Value("Tsybius");
	root["age"] = Json::Value(23);
	root["sex_is_male"] = Json::Value(true);

	//子节点
	Json::Value partner;

	//子节点属性
	partner["partner_name"] = Json::Value("Galatea");
	partner["partner_age"] = Json::Value(21);
	partner["partner_sex_is_male"] = Json::Value(false);

	//子节点挂到根节点上
	root["partner"] = Json::Value(partner);

	//数组形式
	root["achievement"].append("ach1");
	root["achievement"].append("ach2");
	root["achievement"].append("ach3");

	//直接输出
	cout << "FastWriter:" << endl;
	Json::FastWriter fw;
	cout << fw.write(root) << endl << endl;

	//缩进输出
	cout << "StyledWriter:" << endl;
	Json::StyledWriter sw;
	cout << sw.write(root) << endl << endl;

	//输出到文件
	ofstream os;
	os.open("PersonalInfo");
	os << sw.write(root);
	os.close();

	return 0;
}

int main() {
	
	ReadJsonFile();
	toStringRead();
	saveJsonFile();
	return 0;
}