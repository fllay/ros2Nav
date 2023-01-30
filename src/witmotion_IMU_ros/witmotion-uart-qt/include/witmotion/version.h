namespace witmotion
{

static const std::string library_version()
{
    return "0.11.18-alpha~dev_0169b9e";
}

}

#include <QtGlobal>
#if QT_VERSION < QT_VERSION_CHECK(5, 14, 0)
    #define ENDL endl
    #define HEX hex
    #define DEC dec
#else
    #define ENDL Qt::endl
    #define HEX Qt::hex
    #define DEC Qt::dec
#endif
