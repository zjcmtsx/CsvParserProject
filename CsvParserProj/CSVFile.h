#pragma once

#include <fstream>
#include <iostream>
#include "Common.h"

using namespace std;



/*
表格格式约定：
	1. 第1行是字段（列）的中文描述
	2. 第2行是字段名，keyName
	3. 第3行是字段数据类型(仅仅用来看看)
	4. 第4行起是数据
*/
class CSVRow;
typedef std::vector<CSVRow*> CSVRowVector;
class CSVFile
{
	friend class CSVRow;

public:
    CSVFile();
	virtual ~CSVFile();

	bool loadFile(const char* szFileName);
	
	CSVRow* GetRow(const int& row);

	int GetRowCount();

	int GetRowInt(const int& row, const string& keyName);
	double GetRowDouble(const int& row, const string& keyName);
	string GetRowString(const int& row, const string& keyName);
	long long GetRowLongLong(const int& row, const string& keyName);

private:
    //以指定分隔符从一行数据中获取关键字列表
    bool Split(const string& strLine, StringVector& vecString);

	// 通过列名获取对应的列下标， 返回值小于0说明没找到
	int KeyNameToIndex(const string& keyName);

	// 获取第row行（从0开始），列名是keyName的字段值
	string GetFieldValue(const int& row, const string& keyName);


protected:
    CSVRowVector	m_rowsVec;
	StringIntMap	m_keyNameIndexMap;
};
