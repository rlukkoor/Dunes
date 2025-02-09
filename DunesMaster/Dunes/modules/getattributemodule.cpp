#include "getattributemodule.h"
#include "modulelistitem.h"
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

const QString GetAttributeModule::title = "GetAttribute";
const QString GetAttributeModule::description = "Gets an HTML attribute from the first element in the input stream. The value of the attribute will go to the input stream.";

GetAttributeModule::GetAttributeModule()
{
    m_titleLabel->setText(title);
    QLabel* inputTypeLabel = new QLabel("Attribute:");
    QGridLayout* optionsLayout = new QGridLayout();
    optionsLayout->setAlignment(Qt::AlignTop);
    optionsLayout->addWidget(inputTypeLabel, 0, 0);
    m_optionsPanel->setLayout(optionsLayout);

    SelectBox = new QLineEdit();
    optionsLayout->addWidget(SelectBox, 0, 1);

}

QString GetAttributeModule::getCode(){
    if(SelectBox->text().length() == 0) {
        return COMPILE_ERROR;
    }
    return "attribute(\""+escapeString(SelectBox->text())+"\");\n";
}

QString GetAttributeModule::getConfig(QString col){
    return "type=" + QString::number(type) + ";" + "col=" + col + ";" + "attribute=" + SelectBox->text() + ";\n";
}

bool GetAttributeModule::setConfig(QString variable, QString value) {
    if (variable == "attribute") {
        SelectBox->setText(value);
        return true;
    } else {
        qInfo() << "Can't parse data: var: " << variable << "val: " << value << endl;
        return false;
    }
}
