#pragma once

#include <vector>
#include <map>
#include <string>

using namespace std;

typedef std::vector< string > StringVector;
typedef std::map<string, int > StringIntMap;



const unsigned int DESCRIPTION_ROW_INDEX	= 0;	//字段说明desc在csv表中的行号
const unsigned int NAME_ROW_INDEX			= 1;	//字段名称name在csv表中的行号
const unsigned int KEY_TYPE_ROW_INDEX		= 2;	//字段类型type在csv表中的行号
const unsigned int KEY_TYPE_ROW_NUM			= KEY_TYPE_ROW_INDEX + 1;	//字段类型在csv表中的行数

