#include <QtTest>
#include <QCoreApplication>

#include <../CU_source_code/is_valid.hpp>
#include <../CU_source_code/compound_unit.hpp>
#include <../CU_source_code/base_unit.hpp>
#include <../CU_source_code/base_unit_traits.hpp>
#include <string>
// add necessary includes here

class compound_unit : public QObject
{
    Q_OBJECT

public:
    compound_unit();
    ~compound_unit();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

    void testCompoundUnitTemplate();
    void testIsValidTemplate();
    void testMergingCompoundUnits();
    void testCondensingCompoundUnits();
    void testMultiplyingCompoundUnits();
    void testDividingCompoundUnits1();
    void testDividingCompoundUnits2();
    void testRemovingZeroEqualDegres();
    void testUnfoldingNestedCompoundUnits();
    void testFormatingCompoundUnits1();
    void testFormatingCompoundUnits2();

};

//-----------------------------------------------
void compound_unit::testCompoundUnitTemplate(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-1>>;
    using cout_format = unit::to_str_type_t<acceleration>;

    std::string return_value=cout_format::str();
    const char *expected_value="m^1s^-1";

    QCOMPARE(return_value, expected_value);
}

void compound_unit::testMergingCompoundUnits(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-2>>;

    using merged = unit::merge_t<acceleration,
                                 unit::compound_unit<unit::second<3>,
                                                     unit::second<2>>>;
    using merged_cout_format = unit::to_str_type_t<merged>;
    std::string return_value=merged_cout_format::str();

    const char *expected_value="s^2s^3m^1s^-2";

    QCOMPARE(return_value, expected_value);
}

void compound_unit::testCondensingCompoundUnits(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-2>>;
    //using cout_format = unit::to_str_type_t<acceleration>;

    using merged = unit::merge_t<acceleration,
                                 unit::compound_unit<unit::second<3>,
                                                     unit::second<2>>>;
    //using merged_cout_format = unit::to_str_type_t<merged>;


    using condensed = unit::condense_t<merged>;
    using condensed_cout_format = unit::to_str_type_t<condensed>;
    std::string return_value=condensed_cout_format::str();
    const char *expected_value="s^3m^1";
    QCOMPARE(return_value, expected_value);
}

void compound_unit::testMultiplyingCompoundUnits(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-2>>;

    //using merged = unit::merge_t<acceleration,
    //                             unit::compound_unit<unit::second<3>,
    //                                                 unit::second<2>>>;

    using some_unit = unit::compound_unit<unit::second<-1>, unit::meter<4>>;

    using multiplied = unit::multiply_t<acceleration,
                                        some_unit>;
    using multiplied_cout_format = unit::to_str_type_t<multiplied>;

    std::string return_value=multiplied_cout_format::str();
    const char *expected_value="m^5s^-3";
    QCOMPARE(return_value, expected_value);
}

void compound_unit::testDividingCompoundUnits1(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-2>>;
    using some_unit = unit::compound_unit<unit::second<-1>, unit::meter<4>>;
    using multiplied = unit::multiply_t<acceleration,
                                        some_unit>;
    using divided = unit::divide_t<multiplied,
                                   some_unit>;

    using divided_cout_format = unit::to_str_type_t<divided>;

    std::string return_value=divided_cout_format::str();
    const char *expected_value="m^1s^-2";
    QCOMPARE(return_value, expected_value);
}
void compound_unit::testDividingCompoundUnits2(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-2>>;
    using some_unit = unit::compound_unit<unit::second<-1>, unit::meter<4>>;
    using multiplied = unit::multiply_t<acceleration,
                                        some_unit>;
    using divided = unit::divide_t<multiplied,
                                   some_unit>;

    using divided_again = unit::divide_t<divided,
                                         unit::compound_unit<unit::second<-2>>>;
    using divided_again_cout_format = unit::to_str_type_t<divided_again>;

    std::string return_value=divided_again_cout_format::str();
    const char *expected_value="m^1s^0";
    QCOMPARE(return_value, expected_value);
}
void compound_unit::testRemovingZeroEqualDegres(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-2>>;
    using some_unit = unit::compound_unit<unit::second<-1>, unit::meter<4>>;
    using multiplied = unit::multiply_t<acceleration,
                                        some_unit>;
    using divided = unit::divide_t<multiplied,
                                   some_unit>;

    using divided_again = unit::divide_t<divided,
                                         unit::compound_unit<unit::second<-2>>>;

    using removed_zero = unit::remove_zero_cu_degree_t<divided_again>;
    using removed_zero_cout_format = unit::to_str_type_t<removed_zero>;

    std::string return_value=removed_zero_cout_format::str();
    const char *expected_value="m^1";
    QCOMPARE(return_value, expected_value);
}

void compound_unit::testUnfoldingNestedCompoundUnits(){
   /*
    * Defining a nested compound_unit
    * (a compound_unit whose elements
    * can also be other compound_units).
    */
    using nested_cu = unit::compound_unit<unit::meter<2>,
                                          unit::compound_unit<>,
                                          unit::compound_unit<unit::meter<6>,
                                          unit::compound_unit<unit::second<-4>,
                                          unit::meter<-8>>>>;
   /*
    * Here we are unfolding a nested compound_unit.
    */
    using unfolded = unit::unfold_t<nested_cu>;
    using unfolded_cout_format = unit::to_str_type_t<unfolded>;

    std::string return_value=unfolded_cout_format::str();
    const char *expected_value="m^2m^6s^-4m^-8";
    QCOMPARE(return_value, expected_value);
}

void compound_unit::testFormatingCompoundUnits1(){
   /*
    * Defining a nested compound_unit
    * (a compound_unit whose elements
    * can also be other compound_units).
    */
    using nested_cu = unit::compound_unit<unit::meter<2>,
                                          unit::compound_unit<>,
                                          unit::compound_unit<unit::meter<6>,
                                          unit::compound_unit<unit::second<-4>,
                                                              unit::meter<-8>>>>;
   /*
    * Here we are unfolding a nested compound_unit.
    */
    using unfolded = unit::unfold_t<nested_cu>;

   /*
    * Since the resulting compound_unit is not condensed
    * and potentially has degrees that are equal to zero,
    * we are here formating the resulting compound_unit.
    */
    using formated_h = unit::condense_t<unfolded>;
    using formated_f = unit::remove_zero_cu_degree_t<formated_h>;
    using formated_f_cout_format = unit::to_str_type_t<formated_f>;

    std::string return_value=formated_f_cout_format::str();
    const char *expected_value="s^-4";
    QCOMPARE(return_value, expected_value);
}

void compound_unit::testFormatingCompoundUnits2(){
    using nested_cu = unit::compound_unit<unit::meter<3>,
                                          unit::compound_unit<>,
                                          unit::compound_unit<unit::meter<7>,
                                          unit::compound_unit<unit::second<-6>,
                                                              unit::meter<-8>>>>;
   /*
    * Here we are unfolding a nested compound_unit.
    */
    using unfolded = unit::unfold_t<nested_cu>;

   /*
    * Since the resulting compound_unit is not condensed
    * and potentially has degrees that are equal to zero,
    * we are here formating the resulting compound_unit.
    */
    using formated_h = unit::condense_t<unfolded>;
    //using formated_f = unit::remove_zero_cu_degree_t<formated_h>;
    //using formated_f_cout_format = unit::to_str_type_t<formated_f>;
    using formated_f_cout_format = unit::to_str_type_t<formated_h>;

    std::string return_value=formated_f_cout_format::str();
    const char *expected_value="m^2s^-6";
    QCOMPARE(return_value, expected_value);
}

void compound_unit::testIsValidTemplate(){

}
//-----------------------------------------------


compound_unit::compound_unit()
{

}

compound_unit::~compound_unit()
{

}

void compound_unit::initTestCase()
{

}

void compound_unit::cleanupTestCase()
{

}

void compound_unit::test_case1()
{

}

QTEST_MAIN(compound_unit)

#include "tst_compound_unit.moc"
