#include <Windows.h>
#include <uiconnector.h>
#include <QDebug>

void UiConnector::setSampleText(const QString sampleText) {
  std::cout << "setSampleText: " << sampleText.toStdString() << std::endl;
  mText = sampleText + QString("dupa");
  emit sampleTextChanged(mText);
}

QString UiConnector::sampleText() const {
  std::cout << "sampleText" << std::endl;
  return mText;
}

void UiConnector::callMe()
{
    std::cout << "callMe " << std::endl;
}

QString UiConnector::someVar()
{
    return m_someVar;
}

void UiConnector::setSomeVar(QString str)
{

    if(m_someVar != str)
    {
        m_someVar = str;
        emit someVarChanged();
    }
}

void UiConnector::Dupa()
{
    int a = 0;

    while(true)
    {
        a++;
        Sleep(1000);
        setSomeVar(QString::number(a));
    }

}
