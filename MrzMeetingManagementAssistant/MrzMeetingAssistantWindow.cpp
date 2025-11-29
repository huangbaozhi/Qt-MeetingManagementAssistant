#include "MrzMeetingAssistantWindow.h"
#include "view/MrzTopTitleBarWidget.h"
#include "view/MrzLeftMenuBarWidget.h"
#include "view/MrzCentralContentStackedWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

/**
 * @file MrzMeetingAssistantWindow.cpp
 * @brief MrzMeetingAssistantWindow
 * @details 会议管理助手
 * @author Muruz
 * @email 653975671@qq.com
 * @version 1.0.0
 * @date 2025.11.29
 */

MrzMeetingAssistantWindow::MrzMeetingAssistantWindow(QWidget *parent)
    : QWidget{parent}
{
    initUI();
}

void MrzMeetingAssistantWindow::initUI()
{
    QHBoxLayout *pShowMainLyt = new QHBoxLayout(this);
    pShowMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setMinimumSize(1440, 900);
    pMainWgt->setStyleSheet("QWidget{border-radius: 0px 0px 0px 0px;background-color: rgba(245,245,249,1);}");
    pShowMainLyt->addWidget(pMainWgt);

    QVBoxLayout *pMainLyt = new QVBoxLayout(pMainWgt);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    // 标题栏
    m_pMrzTitleBarWidget = new MrzTitleBarWidget(this);

    // 左侧栏
    QHBoxLayout *pContentLyt = new QHBoxLayout;
    pContentLyt->setContentsMargins(0, 0, 0, 0);

    m_pMrzLeftMenuBarWidget = new MrzLeftMenuBarWidget(this);
    pContentLyt->addWidget(m_pMrzLeftMenuBarWidget);

    // 栈窗口
    m_pMrzCentralContentStackedWidget = new MrzCentralContentStackedWidget(this);
    pContentLyt->addWidget(m_pMrzCentralContentStackedWidget);

    pMainLyt->setSpacing(0);
    pMainLyt->addWidget(m_pMrzTitleBarWidget);
    pMainLyt->setSpacing(0);
    pMainLyt->addLayout(pContentLyt);
    pMainLyt->setSpacing(0);

}
