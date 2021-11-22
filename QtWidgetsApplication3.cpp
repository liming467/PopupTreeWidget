#include "QtWidgetsApplication3.h"
#include "OsgWidget.h"
#include <QStyleFactory>
#include <QDebug>



QtWidgetsApplication3::QtWidgetsApplication3(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    /*OsgWidget* aa = new OsgWidget(this);
    setCentralWidget(aa);*/

    m_treeWidget = ui.treeWidget;
    m_treeWidget->setStyle(QStyleFactory::create("windows"));//��������
	m_treeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);//���Զ�ѡ
	
	createMenu();
    addTreeNode();

	connect(m_treeWidget, &QTreeWidget::itemPressed, this, &QtWidgetsApplication3::slot_itemPressed);
}


void QtWidgetsApplication3::createMenu()
{
	m_actionShow = new QAction("Show", m_treeWidget);//��Ϊ����QTreeWidget��ʵ���Ҽ�������������Ϊ����
	m_actionHide = new QAction("Hide", m_treeWidget);//��Ϊ����QTreeWidget��ʵ���Ҽ�������������Ϊ����
	connect(m_actionShow, &QAction::triggered, this, &QtWidgetsApplication3::slot_show);
	connect(m_actionHide, &QAction::triggered, this, &QtWidgetsApplication3::slot_hide);

	m_actionShowStatusMenu = new QMenu(m_treeWidget);
	m_actionShowStatusMenu->addAction(m_actionShow);
	m_actionShowStatusMenu->addAction(m_actionHide);	
}

void QtWidgetsApplication3::addTreeNode()
{
	//��һ��
	QTreeWidgetItem* group1 = new QTreeWidgetItem(m_treeWidget);
	group1->setText(0, "group1");
	group1->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

	QTreeWidgetItem* item11 = new QTreeWidgetItem(group1);
	item11->setText(0, "item11");
	item11->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	QTreeWidgetItem* item12 = new QTreeWidgetItem(group1);
	item12->setText(0, "item12");
	item12->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	QTreeWidgetItem* item13 = new QTreeWidgetItem(group1);
	item13->setText(0, "item13");
	item13->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

	//�ڶ���
	QTreeWidgetItem* group2 = new QTreeWidgetItem(m_treeWidget);
	group2->setText(0, "group2");
	group2->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	QTreeWidgetItem* item21 = new QTreeWidgetItem(group2);
	item21->setText(0, "item21");
	item21->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	QTreeWidgetItem* item22 = new QTreeWidgetItem(group2);
	item22->setText(0, "item22");	
}

void QtWidgetsApplication3::showItem(QTreeWidgetItem* item)
{
	int count = item->childCount();
	if (count == 0)//û���ӽڵ�
	{
		item->setTextColor(0, Qt::black);
		return;
	}

	for (int i = 0; i < count; i++)
	{
		QTreeWidgetItem* childItem = item->child(i);
		showItem(childItem);
	}
	item->setTextColor(0, Qt::black);//��ʾ�Լ�
}

void QtWidgetsApplication3::hideItem(QTreeWidgetItem* item)
{
	int count = item->childCount();
	if (count == 0)//û���ӽڵ�
	{
		item->setTextColor(0, Qt::lightGray);
	}
	else {
		for (int i = 0; i < count; i++)
		{
			QTreeWidgetItem* childItem = item->child(i);
			hideItem(childItem);
		}
	}	
	item->setTextColor(0, Qt::lightGray);//�����Լ�
}


void QtWidgetsApplication3::slot_show(bool status)
{
	//m_selectedItem->setTextColor(0, Qt::black);
	QList<QTreeWidgetItem*> selectedItemList = m_treeWidget->selectedItems();
	for (int i = 0; i < selectedItemList.size(); i++)
	{
		QTreeWidgetItem* item = selectedItemList[i];
		if (item->childCount())
			item->setTextColor(0, Qt::black);
		showItem(item);
	}
}


void QtWidgetsApplication3::slot_hide(bool status)
{
	QList<QTreeWidgetItem*> selectedItemList = m_treeWidget->selectedItems();
	for (int i = 0; i < selectedItemList.size(); i++)
	{
		QTreeWidgetItem* item = selectedItemList[i];
		if (item->childCount())
			item->setTextColor(0, Qt::lightGray);
		hideItem(item);
	}
}


void QtWidgetsApplication3::slot_itemPressed(QTreeWidgetItem* pressedItem, int column)
{
	if (qApp->mouseButtons() == Qt::RightButton)//�ж��Ƿ�Ϊ�Ҽ�
	{
		m_selectedItem = pressedItem;
		m_selectedColumn = column;		
		m_actionShowStatusMenu->exec(QCursor::pos());//�˵�����λ��Ϊ�����λ��
	}
}
