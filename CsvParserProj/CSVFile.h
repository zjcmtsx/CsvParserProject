#pragma once

#include <fstream>
#include <iostream>
#include "Common.h"

using namespace std;



/*
����ʽԼ����
	1. ��1�����ֶΣ��У�����������
	2. ��2�����ֶ�����keyName
	3. ��3�����ֶ���������(������������)
	4. ��4����������
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
    //��ָ���ָ�����һ�������л�ȡ�ؼ����б�
    bool Split(const string& strLine, StringVector& vecString);

	// ͨ��������ȡ��Ӧ�����±꣬ ����ֵС��0˵��û�ҵ�
	int KeyNameToIndex(const string& keyName);

	// ��ȡ��row�У���0��ʼ����������keyName���ֶ�ֵ
	string GetFieldValue(const int& row, const string& keyName);


protected:
    CSVRowVector	m_rowsVec;
	StringIntMap	m_keyNameIndexMap;
};
