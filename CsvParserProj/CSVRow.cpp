#include "CSVRow.h"
#include "CSVFile.h"

CSVRow::CSVRow()
{
	m_csvFile = nullptr;
	m_rowValueVec.clear();
}

CSVRow::CSVRow(CSVFile* csvFile, StringVector& valueVec)
{
	m_csvFile = csvFile;
	m_rowValueVec.clear();
	m_rowValueVec.insert(m_rowValueVec.begin(), valueVec.begin(), valueVec.end());
}

const StringVector& CSVRow::GetRowValueVec()
{
	return m_rowValueVec;
}

string CSVRow::GetValueString(const int& index)
{
	if (index >= 0 && index < int(m_rowValueVec.size()))
	{
		return m_rowValueVec[index];
	}
	return "";
}


int CSVRow::GetRowInt(const string& keyName)
{
	int index = m_csvFile->KeyNameToIndex(keyName);
	if(index >= 0)
	{
		return atoi(m_rowValueVec[index].c_str());
	}
	return 0;
}
double CSVRow::GetRowDouble(const string& keyName)
{
	int index = m_csvFile->KeyNameToIndex(keyName);
	if(index >= 0)
	{
		return atof(m_rowValueVec[index].c_str());
	}
	return 0.0f;
}
string CSVRow::GetRowString(const string& keyName)
{
	int index = m_csvFile->KeyNameToIndex(keyName);
	if(index >= 0)
	{
		return m_rowValueVec[index];
	}
	return "";
}
long long CSVRow::GetRowLongLong(const string& keyName)
{
	int index = m_csvFile->KeyNameToIndex(keyName);
	if(index >= 0)
	{
		const string& valueStr = m_rowValueVec[index];
		return atoll(valueStr.c_str());
	}
	return 0;
}