#pragma once

#include <vector>
#include <map>
#include <string>

using namespace std;

typedef std::vector< string > StringVector;
typedef std::map<string, int > StringIntMap;



const unsigned int DESCRIPTION_ROW_INDEX	= 0;	//�ֶ�˵��desc��csv���е��к�
const unsigned int NAME_ROW_INDEX			= 1;	//�ֶ�����name��csv���е��к�
const unsigned int KEY_TYPE_ROW_INDEX		= 2;	//�ֶ�����type��csv���е��к�
const unsigned int KEY_TYPE_ROW_NUM			= KEY_TYPE_ROW_INDEX + 1;	//�ֶ�������csv���е�����

