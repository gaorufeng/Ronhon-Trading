// MdUserApi.h: interface for the CMdUserApi class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDUSERAPI_H__EB15FB7E_0B26_46DA_A48C_4D66C5007855__INCLUDED_)
#define AFX_MDUSERAPI_H__EB15FB7E_0B26_46DA_A48C_4D66C5007855__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ThostFtdcMdApi.h"

class CAutomationDemoDlg;
class CMdUserApi : public CThostFtdcMdSpi  
{
public:
	CMdUserApi();
	virtual ~CMdUserApi();
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason);
	
	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///����Ӧ��
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///��������Ӧ��
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///ȡ����������Ӧ��
	virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	
	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
public:
	void Init(FILE* pLog, char* szAddress);
	void SubscribeMarketData(char *pInstrumentID);
	void FormatLog( int nLevel, CString strDomain, CString strText );
	void SetMainDlg(CAutomationDemoDlg* pDlg) { m_pMainDlg = pDlg; }
private:
	CThostFtdcMdApi*			m_pMDApi;
	FILE*						m_pLog;
	int							m_nRequestID;
	CAutomationDemoDlg*			m_pMainDlg;
};

#endif // !defined(AFX_MDUSERAPI_H__EB15FB7E_0B26_46DA_A48C_4D66C5007855__INCLUDED_)
