
// TargetDemo_SDI_2View.cpp : CTargetDemo_SDI_2View Ŭ������ ����
//

#include "stdafx.h"
#include "../Xmlparser/tinyxml2.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "TargetDemo_SDI_2.h"
#endif

#include "TargetDemo_SDI_2Doc.h"
#include "TargetDemo_SDI_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTargetDemo_SDI_2View

IMPLEMENT_DYNCREATE(CTargetDemo_SDI_2View, CFormView)

BEGIN_MESSAGE_MAP(CTargetDemo_SDI_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CTargetDemo_SDI_2View::OnBnClickedButtonLoad)
	ON_BN_DOUBLECLICKED(IDC_BUTTON_SAVE, &CTargetDemo_SDI_2View::OnBnDoubleclickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_INPUT, &CTargetDemo_SDI_2View::OnBnClickedButtonInput)
	ON_BN_CLICKED(IDC_BUTTON_Clear, &CTargetDemo_SDI_2View::OnBnClickedButtonClear)
END_MESSAGE_MAP()

// CTargetDemo_SDI_2View ����/�Ҹ�

CTargetDemo_SDI_2View::CTargetDemo_SDI_2View()
	: CFormView(IDD_TARGETDEMO_SDI_2_FORM)
	, ti_id(0)
	, ti_type(0)
	, ti_x(0)
	, ti_y(0)
	, ti_path(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CTargetDemo_SDI_2View::~CTargetDemo_SDI_2View()
{
}

void CTargetDemo_SDI_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, ti_id);
	DDX_Text(pDX, IDC_EDIT_TYPE, ti_type);
	DDX_Text(pDX, IDC_EDIT_X, ti_x);
	DDX_Text(pDX, IDC_EDIT_Y, ti_y);
	DDX_Text(pDX, IDC_EDIT_PATH, ti_path);
	DDX_Control(pDX, IDC_GRID, m_Grid);
}

BOOL CTargetDemo_SDI_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CTargetDemo_SDI_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_Grid.SetEditable(false);
	m_Grid.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//yellow background
	m_Grid.SetRowCount(1); //
	m_Grid.SetColumnCount(5); //
	m_Grid.SetFixedRowCount(1); //

	for (int row = 0; row < m_Grid.GetRowCount(); row++)
		for (int col = 0; col < m_Grid.GetColumnCount(); col++)
		{

			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.row = row;
			Item.col = col;

			m_Grid.SetRowHeight(row, 30); //set row heigh          
			//m_Grid.SetColumnWidth(0, 118); //set column width 
			m_Grid.SetColumnWidth(col, 118); //

			if (row == 0 && col == 0) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T("ID"), col);
			}
			else if (row == 0 && col == 1) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T(" Type "), col);
			}
			else if (row == 0 && col == 2) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T(" X "), col);
			}
			else if (row == 0 && col == 3) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T(" Y "), col);
			}
			else if (row == 0 && col == 4) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T(" Path "), col);
			}
			else
			{
				Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
				Item.strText.Format(_T(""), 2);
			}
			m_Grid.SetItem(&Item);
		}

}


// CTargetDemo_SDI_2View ����

#ifdef _DEBUG
void CTargetDemo_SDI_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CTargetDemo_SDI_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTargetDemo_SDI_2Doc* CTargetDemo_SDI_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTargetDemo_SDI_2Doc)));
	return (CTargetDemo_SDI_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CTargetDemo_SDI_2View �޽��� ó����


void CTargetDemo_SDI_2View::OnBnClickedButtonLoad()
{
	CString str = _T("XML files(*.xml)|*.xml");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, str, this);
	if (IDOK == dlg.DoModal())
	{
		tVector.clear();

		CString strPathName = dlg.GetPathName();
		tinyxml2::XMLDocument doc;
		doc.LoadFile((CStringA)strPathName);

		// Root Node ����
		tinyxml2::XMLElement* pRootNode = doc.FirstChildElement("Target_Information");
		if (NULL == pRootNode)
			return;
		// ����� ��Ʈ����Ʈ ���� ���
		// ���ϴ� Node�� Element ���� �� �� �б�

		// "Field"�� ����� ������ ��Ʈ����Ʈ���� �ݺ�
		for (tinyxml2::XMLElement* pNodeElem = pRootNode->FirstChildElement("Field"); pNodeElem; pNodeElem = pNodeElem->NextSiblingElement())
		{
			tinyxml2::XMLAttribute* pAttribute = (tinyxml2::XMLAttribute*)pNodeElem->FirstAttribute(); //���� ����� ù��° ��Ʈ����Ʈ ������ �̵�

			targetInform ti;
			ti.id = pAttribute->IntValue();									// ���� Int�� ��ȯ�Ͽ� ����

			pAttribute = (tinyxml2::XMLAttribute*)pAttribute->Next();		// �������� �̵�
			ti.type = pAttribute->IntValue();								// ���� Int�� ��ȯ�Ͽ� ����

			pAttribute = (tinyxml2::XMLAttribute*)pAttribute->Next();		// �������� �̵�
			ti.x = pAttribute->DoubleValue();								// ���� double�� ��ȯ�Ͽ� ����

			pAttribute = (tinyxml2::XMLAttribute*)pAttribute->Next();		// �������� �̵�
			ti.y = pAttribute->DoubleValue();								// ���� double�� ��ȯ�Ͽ� ����    

			pAttribute = (tinyxml2::XMLAttribute*)pAttribute->Next();		// �������� �̵�
			const char* pszAttribute = pAttribute->Value();					// pszAttribute=Data

			ti.path = (CString)pszAttribute;
			tVector.push_back(ti);											// vector�� ����
		}
		ShowGrid();
	}

}


void CTargetDemo_SDI_2View::OnBnDoubleclickedButtonSave()
{
	CString str = _T("XML files(*.xml)|*.xml");
	CFileDialog dlg(false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, str, this);
	if (IDOK == dlg.DoModal())
	{
		tinyxml2::XMLDocument doc;
		tinyxml2::XMLDeclaration* pDecl = doc.NewDeclaration();
		doc.LinkEndChild(pDecl);

		// Root Node
		tinyxml2::XMLElement* pRootNode = doc.NewElement("Target_Information");
		doc.LinkEndChild(pRootNode);

		// child Node
		for (int i = 0; i < tVector.size(); i++)
		{
			targetInform ti;
			ti = tVector.at(i);
			tinyxml2::XMLElement* pNode = doc.NewElement("Field");
			pRootNode->LinkEndChild(pNode);
			pNode->SetAttribute("id", ti.id);     //id
			pNode->SetAttribute("type", ti.type); //type
			pNode->SetAttribute("x", ti.x); // X (�Ҽ���)
			pNode->SetAttribute("y", ti.y); // Y (�Ҽ���)
			pNode->SetAttribute("path", (CStringA)ti.path);
		}

		// .xml ����
		CString strSavePathName = dlg.GetPathName();
		doc.SaveFile((CStringA)strSavePathName);

	}
}


void CTargetDemo_SDI_2View::OnBnClickedButtonInput()
{
	UpdateData();
	VectorAdd(ti_id, ti_type, ti_x, ti_y, ti_path);
	ShowGrid();

}


void CTargetDemo_SDI_2View::OnBnClickedButtonClear()
{
	int nRow = m_Grid.GetFocusCell().row;
	if (nRow >= 0)
	{
		tVec_it = tVector.begin() + (nRow - 1);
		tVector.erase(tVec_it);
		m_Grid.DeleteRow(nRow);
		m_Grid.Invalidate();
	}
}


void CTargetDemo_SDI_2View::VectorAdd(int id, int type, double x, double y, CString path)
{
	targetInform ti;
	ti.id = id;
	ti.type = type;
	ti.x = x;
	ti.y = y;
	ti.path = path;
	tVector.push_back(ti);
}

void CTargetDemo_SDI_2View::ShowGrid()
{
	m_Grid.SetRowCount(tVector.size() + 1);
	for (int row = 0; row < tVector.size(); row++)
	{
		targetInform ti;
		ti = tVector.at(row);
		for (int col = 0; col < m_Grid.GetColumnCount(); col++)
		{
			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.row = row + 1;
			Item.col = col;
			if (col == 0) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T("%d"), ti.id);
			}
			if (col == 1) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T("%d"), ti.type);
			}
			if (col == 2) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T("%f"), ti.x);
			}
			if (col == 3) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T("%f"), ti.y);
			}
			if (col == 4) //
			{
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T("%s"), ti.path);
			}
			m_Grid.SetItem(&Item);
		}
	}
	m_Grid.Invalidate();
}