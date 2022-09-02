#include <uiconnector.h>

void UiConnector::setSampleText(const QString sampleText) {
  std::cout << "setSampleText: " << sampleText.toStdString() << std::endl;
  mText = sampleText;
  emit sampleTextChanged(mText);
}

QString UiConnector::sampleText() const {
  std::cout << "sampleText" << std::endl;
  return mText;
}
