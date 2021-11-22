#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication3.h"
#include <QTreeWidget>
#include <QMessageBox>


class QtWidgetsApplication3 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication3(QWidget *parent = Q_NULLPTR);

private slots:
    void slot_show(bool status);   //��QAction������Ĳۺ���
    void slot_hide(bool status);
    void slot_itemPressed(QTreeWidgetItem*, int);


private:
    Ui::QtWidgetsApplication3Class ui;

    void addTreeNode();
    void createMenu();
    void showItem(QTreeWidgetItem* item);
    void hideItem(QTreeWidgetItem* item);

    QTreeWidget*                m_treeWidget = nullptr;
    QMenu*                      m_actionShowStatusMenu = nullptr;
    QAction*                    m_actionShow = nullptr;   //�Զ����QAction
    QAction*                    m_actionHide = nullptr;   //�Զ����QAction

    QTreeWidgetItem*            m_selectedItem = nullptr;
    int                         m_selectedColumn = 0;

    
};
