#include "MrzPushButton.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

/**
 * @brief MrzPushButton::MrzPushButton
 * @param parent
 */
MrzPushButton::MrzPushButton(QWidget *parent)
    : QPushButton{parent}
    , m_pMainWgt(nullptr)
    , m_pLogoLbl(nullptr)
    , m_pTextLbl(nullptr)
    , m_normalColor(115, 116, 255, 255)    // 默认正常状态颜色
    , m_hoverColor(95, 96, 235, 255)       // 默认悬停状态颜色
    , m_pressedColor(75, 76, 215, 255)     // 默认按下状态颜色
    , m_currentState(StateNormal)
{
    this->setFixedSize(231, 48);
    initButtonStyle();
}

void MrzPushButton::initButtonStyle()
{
    QHBoxLayout *pMainLyt = new QHBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    m_pMainWgt = new QWidget(this);
    m_pMainWgt->setStyleSheet("QWidget{border-radius: 8px;background-color: rgba(115,116,255,1);border: 0px;}");
    QHBoxLayout *pBtnLyt = new QHBoxLayout(m_pMainWgt);
    pBtnLyt->setContentsMargins(0, 0, 0, 0);

    // logo
    m_pLogoLbl = new QLabel(this);
    m_pLogoLbl->setFixedSize(20, 20);
    //m_pLogoLbl->setStyleSheet("QLabel{image: url(:/images/home.png);background-color:rgba(0,0,0,0);}");

    // text
    m_pTextLbl = new QLabel(this);
    m_pTextLbl->setStyleSheet("QLabel{line-height: 24px;color: rgba(255,255,255,1);font-size: 16px;text-align: justify;font-family: NotoSans-regular;}");

    pBtnLyt->addSpacing(16);
    pBtnLyt->addWidget(m_pLogoLbl);
    pBtnLyt->addSpacing(12);
    pBtnLyt->addWidget(m_pTextLbl);
    pBtnLyt->addSpacing(151);

    pMainLyt->addWidget(m_pMainWgt);

    // 初始化样式和图标
    updateButtonStyle();
    updateIcon();
}

void MrzPushButton::setButtonText(const QString &text)
{
    m_pTextLbl->setText(text);
}

void MrzPushButton::updateButtonStyle()
{
    QColor currentColor;

    switch (m_currentState) {
    case StateNormal:
        currentColor = m_normalColor;
        break;
    case StateHover:
        currentColor = m_hoverColor;
        break;
    case StatePressed:
        currentColor = m_pressedColor;
        break;
    }

    QString style = QString("QWidget{"
                            "border-radius: 8px;"
                            "background-color: rgba(%1, %2, %3, %4);"
                            "border: 0px;"
                            "}").arg(currentColor.red())
                        .arg(currentColor.green())
                        .arg(currentColor.blue())
                        .arg(currentColor.alpha());

    m_pMainWgt->setStyleSheet(style);
}

void MrzPushButton::updateIcon()
{
    QString iconPath;

    switch (m_currentState) {
    case StateNormal:
        iconPath = m_normalIcon;
        break;
    case StateHover:
        iconPath = !m_hoverIcon.isEmpty() ? m_hoverIcon : m_normalIcon;
        break;
    case StatePressed:
        iconPath = !m_pressedIcon.isEmpty() ? m_pressedIcon : m_normalIcon;
        break;
    }

    if (!iconPath.isEmpty()) {
        m_pLogoLbl->setStyleSheet(QString("QLabel{image: url(%1);background-color:rgba(0,0,0,0);}").arg(iconPath));
    }
}

void MrzPushButton::setNormalColor(const QColor &color)
{
    m_normalColor = color;
    if (m_currentState == StateNormal)
    {
        updateButtonStyle();
    }
}

void MrzPushButton::setHoverColor(const QColor &color)
{
    m_hoverColor = color;
    if (m_currentState == StateHover)
    {
        updateButtonStyle();
    }
}

void MrzPushButton::setPressedColor(const QColor &color)
{
    m_pressedColor = color;
    if (m_currentState == StatePressed)
    {
        updateButtonStyle();
    }
}

void MrzPushButton::setNormalIcon(const QString &iconPath)
{
    m_normalIcon = iconPath;
    if (m_currentState == StateNormal)
    {
        updateIcon();
    }
}

void MrzPushButton::setHoverIcon(const QString &iconPath)
{
    m_hoverIcon = iconPath;
    if (m_currentState == StateHover)
    {
        updateIcon();
    }
}

void MrzPushButton::setPressedIcon(const QString &iconPath)
{
    m_pressedIcon = iconPath;
    if (m_currentState == StatePressed)
    {
        updateIcon();
    }
}

void MrzPushButton::enterEvent(QEnterEvent *event)
{
    QPushButton::enterEvent(event);
    if (!isEnabled()) return;

    m_currentState = StateHover;
    updateButtonStyle();
    updateIcon();
}

void MrzPushButton::leaveEvent(QEvent *event)
{
    QPushButton::leaveEvent(event);
    if (!isEnabled()) return;

    m_currentState = StateNormal;
    updateButtonStyle();
    updateIcon();
}

void MrzPushButton::mousePressEvent(QMouseEvent *event)
{
    QPushButton::mousePressEvent(event);
    if (!isEnabled()) return;

    m_currentState = StatePressed;
    updateButtonStyle();
    updateIcon();
}

void MrzPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    QPushButton::mouseReleaseEvent(event);
    if (!isEnabled()) return;

    // 判断鼠标是否还在按钮内
    if (rect().contains(event->pos())) {
        m_currentState = StateHover;
    } else {
        m_currentState = StateNormal;
    }
    updateButtonStyle();
    updateIcon();
}


