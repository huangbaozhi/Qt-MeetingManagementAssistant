#include "MrzTopTitleBarWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

/**
 * @brief MrzTitleBarWidget
 * @param parent
 * @details 标题栏
 */

MrzTitleBarWidget::MrzTitleBarWidget(QWidget *parent)
    : QWidget{parent}
{
    initUI();
}

void MrzTitleBarWidget::initUI()
{
    // 标题栏
    QHBoxLayout *pTitleLyt = new QHBoxLayout(this);
    pTitleLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pTitleBarWgt = new QWidget(this);
    pTitleBarWgt->setFixedHeight(60);
    pTitleBarWgt->setStyleSheet("QWidget{border-radius: 0px 0px 0px 0px;background-color: rgba(255,255,255,1);border: 1px solid rgba(226,232,240,1);}");

    QHBoxLayout *pTitleBarLyt = new QHBoxLayout(pTitleBarWgt);
    pTitleBarLyt->setContentsMargins(0, 0, 0, 0);

    m_pTitleLbl = new QLabel(this);
    m_pTitleLbl->setFixedHeight(32);
    m_pTitleLbl->setText("会议管理助手");
    //m_pTitleLbl->setStyleSheet("QLabel{line-height: 28px;color: rgba(45,55,72,1);font-size: 18px;text-align: justify;font-family: NotoSans-semiBold;border: 0px;}");
    m_pTitleLbl->setStyleSheet("QLabel{line-height: 28px;color: rgba(45,55,72,1);font-size: 18px;text-align: justify;font-family: NotoSans-semiBold;border: 0px;}");

    m_pSearchBtn = new QPushButton(this);
    m_pSearchBtn->setFixedSize(32, 32);
    m_pSearchBtn->setStyleSheet("QPushButton{image: url(:/images/search.png);background-color:rgba(0,0,0,0);border: 0px;}");

    m_pMessageBtn = new QPushButton(this);
    m_pMessageBtn->setFixedSize(32, 32);
    m_pMessageBtn->setStyleSheet("QPushButton{image: url(:/images/message.png);background-color:rgba(0,0,0,0);border: 0px;}");

    m_pSetBtn = new QPushButton(this);
    m_pSetBtn->setFixedSize(32, 32);
    m_pSetBtn->setStyleSheet("QPushButton{image: url(:/images/set.png);background-color:rgba(0,0,0,0);border: 0px;}");

    m_pProfilePicLbl = new QLabel(this);
    m_pProfilePicLbl->setFixedSize(32, 32);

    m_pAccountLbl = new QLabel(this);
    m_pAccountLbl->setFixedHeight(32);
    m_pAccountLbl->setText("John Doe");
    m_pAccountLbl->setStyleSheet("QLabel{line-height: 24px;color: rgba(74,85,104,1);font-size: 16px;text-align: justify;font-family: NotoSans-medium;border: 0px;}");

    pTitleBarLyt->addSpacing(32);
    pTitleBarLyt->addWidget(m_pTitleLbl);
    pTitleBarLyt->addStretch();
    pTitleBarLyt->addWidget(m_pSearchBtn);
    pTitleBarLyt->addSpacing(24);
    pTitleBarLyt->addWidget(m_pMessageBtn);
    pTitleBarLyt->addSpacing(24);
    pTitleBarLyt->addWidget(m_pSetBtn);
    pTitleBarLyt->addSpacing(24);
    pTitleBarLyt->addWidget(m_pProfilePicLbl);
    pTitleBarLyt->addSpacing(10);
    pTitleBarLyt->addWidget(m_pAccountLbl);
    pTitleBarLyt->addSpacing(32);

    pTitleLyt->addWidget(pTitleBarWgt);
}
