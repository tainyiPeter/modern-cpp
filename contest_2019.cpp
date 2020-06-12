// contest_2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include <map>
#include <set>

#include <iostream>
#include <time.h>
#include "Timer.hpp"

using namespace std;

//�����¼�����
enum SubEventType {
	subet_Dyna,
	subet_Min,
	subet_Tick,

	subet_total,
};

enum SubWinType {
	swt_hContainer = 0,
	swt_hWnd,
};

#define GLOBAL_STOCKID_CHARSIZE                 16

#define subon 2
#define suboff 3

struct StockID
{
	UCHAR			cMarket;											// �г���Ϣ
	char 			szCode[GLOBAL_STOCKID_CHARSIZE];		// ��Ʊ����

	StockID()
	{
		memset(this, 0, sizeof(StockID));
	}

	StockID(UCHAR c, const char* sz)
		: cMarket(c)
	{
		memcpy(szCode, sz, sizeof(szCode));
	}

	bool operator  < (const StockID& r) const
	{
		if (this->cMarket < r.cMarket) return true;
		else if (this->cMarket > r.cMarket) return false;
		else
		{
			int ret = strcmp(szCode, r.szCode);

			if (ret > 0) 	return true;
			else	return false;
		}
	}

	bool operator  == (const StockID& r) const
	{
		if (cMarket == r.cMarket && strcmp(szCode, r.szCode) == 0) return true;
		else return false;
	}
};

//����ID
struct SubID {
	SubEventType  seType;  //
	StockID		sID;

	SubID()
	{
		memset(this, 0, sizeof(SubID));
	}

	SubID(SubEventType t, UCHAR c, const char* sz)
		:seType(t)
	{
		sID.cMarket = c;
		strcpy_s(sID.szCode, sizeof(sID.szCode), sz);
	}

	bool operator < (const SubID& o) const
	{
		if (seType < o.seType) return true;
		else if (o.seType < seType) return false;
		else
		{
			return sID < o.sID;
		}
	}
};

typedef std::set<__int64>		SubItemType;
typedef std::map<SubID, SubItemType>  hashSubwindowType;

hashSubwindowType	m_subContainerEvents;		//�����¼�,ContainerEvents;
hashSubwindowType	m_subHwndEvents;	//�����¼�,HwndEvents;

void SubEvent(SubEventType seType, UCHAR uMarket, const char* code)
{

	cout << "sub Event " << seType << " uMarket:" << (int)uMarket << " code:" << code << endl;

	switch (seType)
	{
	case subet_Dyna: {
		//cmgr.CreateReqDyna(spInfo, szMarket, code, quote::SubOn);
	}break;
	case subet_Min:
		break;
	case subet_Tick:
		//cmgr.CreateReqTick(spInfo, szMarket, code, quote::SubOn, 0, 0, 0);
		break;
	default:
		break;
	}
}

void UnsubEvent(SubEventType seType, UCHAR uMarket, const char* code)
{
	cout << "unsub Event " << seType << " uMarket:" << (int)uMarket << " code:" << code << endl;
	switch (seType)
	{
	case subet_Dyna: {
	//	cmgr.CreateReqDyna(spInfo, szMarket, code, quote::SubOff);
	}break;
	case subet_Min:
		break;
	case subet_Tick:
	//	cmgr.CreateReqTick(spInfo, szMarket, code, quote::SubOff, 0, 0, 0);
	default:
		break;
	}
}

void CheckSubEvent(SubEventType seType, UCHAR uMarket, const char* code)
{
	SubID  id(seType, uMarket, code);
	auto it = m_subContainerEvents.find(id);
	if (it != m_subContainerEvents.end())
		return;
	it = m_subHwndEvents.find(id);
	if (it != m_subHwndEvents.end())
		return;
	SubEvent(seType, uMarket, code);
}

void CheckUnsubEvent(SubEventType seType, UCHAR uMarket, const char* code)
{
	SubID  id(seType, uMarket, code);
	auto it = m_subContainerEvents.find(id);
	if (it != m_subContainerEvents.end())
		return;
	it = m_subHwndEvents.find(id);
	if (it != m_subHwndEvents.end())
		return;
	UnsubEvent(seType, uMarket, code);
}

void RegSubEvent(SubEventType seType, UCHAR uMarket, const char* code, __int64 hid, \
	SubWinType hWinType, short subType)
{
	//ReqInfoPtr  spInfo(new ReqInfo());
	//cmgr.CreateReqTick(spInfo, "FHSI", "HMHJ0", quote::SubOn, 0, 10, 10);


	SubID  id(seType, uMarket, code);
	if (swt_hContainer == hWinType)
	{
		if (subType == subon)
		{
			auto it = m_subContainerEvents.find(id);
			if (it == m_subContainerEvents.end())
			{
				CheckSubEvent(seType, uMarket, code);
				SubItemType sItems;
				sItems.insert(hid);

				m_subContainerEvents[id] = sItems;
			}
			else
			{
				auto itwin = it->second.find(hid);
				if (itwin == it->second.end())
				{
					it->second.insert(hid);
				}
			}
		}
		else if (subType == suboff)
		{
			auto it = m_subContainerEvents.find(id);
			if (it != m_subContainerEvents.end())
			{
				it->second.erase(hid);
				if (it->second.size() == 0)
				{
					m_subContainerEvents.erase(id);
					CheckUnsubEvent(seType, uMarket, code);
				}
			}
		}
		else
		{
			;
		}
	}
	else if (swt_hWnd == hWinType)
	{
		if (subType == subon)
		{
			auto it = m_subHwndEvents.find(id);
			if (it == m_subHwndEvents.end())
			{
				CheckSubEvent(seType, uMarket, code);
				SubItemType sItems;
				sItems.insert(hid);

				m_subHwndEvents[id] = sItems;
			}
			else
			{
				auto itwin = it->second.find(hid);
				if (itwin == it->second.end())
				{
					it->second.insert(hid);
				}
			}
		}
		else if (subType == suboff)
		{
			auto it = m_subHwndEvents.find(id);
			if (it != m_subHwndEvents.end())
			{
				it->second.erase(hid);
				if (it->second.size() == 0)
				{
					m_subHwndEvents.erase(id);
					CheckUnsubEvent(seType, uMarket, code);
				}
			}
		}
		else
		{
			;
		}
	}
	else
	{
	}
}


struct KLine
{
	long Date;												// ���ڵ���������ʾ(��: 19990101), ������ʱ��
	long Time;												// ʱ�� ����������Ч
	float Open;												// ���̼�
	float Close;											// ���̼�
	float High;												// ��߼�
	float Low;												// ��ͼ�
	unsigned __int64 Volume;								// �ɽ�����
	double Value;											// �ɽ����

	KLine()
	{
		memset(this, 0, sizeof(KLine));
	}

	bool operator < (const KLine& o) const
	{
		return Time < o.Time;
	}
};

//Dyna����ʱ��ָ��ĳЩ�ֶθı�
enum DynaFieldChange
{
	DFC_ZUIXIN = 3,		//����
	DFC_ZHANGDIEFU = 4,		//�ǵ���
	DFC_MAIRUJIA = 6,		//�����
	DFC_MAICHUJIA,		//������
	DFC_ZONGSHOU,		//����
	DFC_XIANSHOU,		//����
	DFC_JINE,			//���
};




void func1()
{
	std::cout << "trigger func1" << std::endl;
}

void func2(int x)
{
	std::cout << "trigger func2, x: " << x << std::endl;
}

//int main(int argc, char* argv[])
//{
//	map<int, string> m;
//	m[1] = "s3s";
//	m[2] = "3j";
//	m[4] = "jin";
//
//	map<int, string>::iterator it = m.begin();
//	for (; it != m.end(); )
//	{
//		if (it->first == 1)
//			it = m.erase(it);
//
//		++it;
//	}
//
//
//	return 0;
//
//	//// execute task every timer interval
//	//std::cout << "--- start period timer ----" << std::endl;
//	//timer.start(1000, std::bind(func2, 3));
//	//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//	//timer.stop();
//	//std::cout << "--- stop period timer ----" << std::endl;
//
//
//	return 0;
//}



