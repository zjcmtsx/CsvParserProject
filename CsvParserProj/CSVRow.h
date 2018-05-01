#pragma once
#include "Common.h"


class CSVFile;


/*
	csv�ļ���һ��
*/
class CSVRow
{

public:
	CSVRow();
	CSVRow(CSVFile* csvFile, StringVector& valueVec);

public:
	const StringVector& GetRowValueVec();

	string GetValueString(const int& index);

	int GetRowInt(const string& keyName);
	double GetRowDouble(const string& keyName);
	string GetRowString(const string& keyName);
	long long GetRowLongLong(const string& keyName);
private:
	CSVFile* m_csvFile;
	StringVector m_rowValueVec;
};
typedef std::vector<CSVRow*> CSVRowVector;
