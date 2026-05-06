#include <gtest/gtest.h>
#include <sstream>

#include "studentas.h"

namespace {
Studentas sukurtasStudentas(const std::string& vardas,
                      const std::string& pavarde,
                      std::initializer_list<int> pazymiai,
                      int egzaminas) {
    Studentas student;
    student.setVardas(vardas);
    student.setPavarde(pavarde);
    for (int pazymys : pazymiai) {
        student.setPaz(pazymys);
    }
    student.setEgz(egzaminas);
    return student;
}
}  // cia sukuriame pagalbine funkcija, kad testuose nereiktu kartoti to pacio ivedimo su studentais

TEST(StudentasKonstruktorius, NumatytosReiksmes) {
    Studentas student;

    EXPECT_EQ(student.getVardas(), "nepriskirtas");//tikriname ar default konstruktorius nustato numatytas reiksmes
    EXPECT_EQ(student.getPavarde(), "nepriskirtas");
    EXPECT_TRUE(student.getPaz().empty());
    EXPECT_EQ(student.getEgz(), 0);
    EXPECT_DOUBLE_EQ(student.Rezultatas(), 0.0);
}

TEST(StudentasRuleOfFive, CopyKonstruktorius) {
    Studentas source = sukurtasStudentas("Jonas", "Jonaitis", {8, 9, 10}, 7);
    source.skaiciuoti_rezultata(1);

    Studentas copy(source);

    EXPECT_EQ(copy.getVardas(), source.getVardas());
    EXPECT_EQ(copy.getPavarde(), source.getPavarde());
    EXPECT_EQ(copy.getPaz(), source.getPaz());
    EXPECT_EQ(copy.getEgz(), source.getEgz());
    EXPECT_DOUBLE_EQ(copy.Rezultatas(), source.Rezultatas());
}

TEST(StudentasRuleOfFive, CopyAssignment) {
    Studentas source = sukurtasStudentas("Ona", "Onaitė", {6, 7, 8}, 9);
    source.skaiciuoti_rezultata(2);

    Studentas target;
    target = source;

    EXPECT_EQ(target.getVardas(), source.getVardas());
    EXPECT_EQ(target.getPavarde(), source.getPavarde());
    EXPECT_EQ(target.getPaz(), source.getPaz());
    EXPECT_EQ(target.getEgz(), source.getEgz());
    EXPECT_DOUBLE_EQ(target.Rezultatas(), source.Rezultatas());
}

TEST(StudentasRuleOfFive, MoveKonstruktorius) {
    Studentas source = sukurtasStudentas("Petras", "Petraitis", {5, 10, 9}, 8);
    source.skaiciuoti_rezultata(1);
    const double expected_result = source.Rezultatas();

    Studentas moved(std::move(source));

    EXPECT_EQ(moved.getVardas(), "Petras");
    EXPECT_EQ(moved.getPavarde(), "Petraitis");
    EXPECT_EQ(moved.getPaz(), std::vector<int>({5, 10, 9}));
    EXPECT_EQ(moved.getEgz(), 8);
    EXPECT_DOUBLE_EQ(moved.Rezultatas(), expected_result);

    EXPECT_TRUE(source.getVardas().empty());
    EXPECT_TRUE(source.getPavarde().empty());
    EXPECT_TRUE(source.getPaz().empty());
    EXPECT_EQ(source.getEgz(), 0);
    EXPECT_DOUBLE_EQ(source.Rezultatas(), 0.0);
}

TEST(StudentasRuleOfFive, MoveAssignment) {
    Studentas source = sukurtasStudentas("Ieva", "Ievaite", {9, 9, 8}, 10);
    source.skaiciuoti_rezultata(1);
    const double expected_result = source.Rezultatas();

    Studentas target;
    target = std::move(source);

    EXPECT_EQ(target.getVardas(), "Ieva");
    EXPECT_EQ(target.getPavarde(), "Ievaite");
    EXPECT_EQ(target.getPaz(), std::vector<int>({9, 9, 8}));
    EXPECT_EQ(target.getEgz(), 10);
    EXPECT_DOUBLE_EQ(target.Rezultatas(), expected_result);

    EXPECT_TRUE(source.getVardas().empty());
    EXPECT_TRUE(source.getPavarde().empty());
    EXPECT_TRUE(source.getPaz().empty());
    EXPECT_EQ(source.getEgz(), 0);
    EXPECT_DOUBLE_EQ(source.Rezultatas(), 0.0);
}

TEST(StudentasRezultatai, NaudojantVidurki) {
    Studentas student = sukurtasStudentas("Mantas", "Mantauskas", {8, 10}, 6);

    student.skaiciuoti_rezultata(1);

    EXPECT_DOUBLE_EQ(student.Rezultatas(), 7.2);
}

TEST(StudentasRezultatai, NaudojantMediana) {
    Studentas student = sukurtasStudentas("Greta", "Gretaite", {7, 9, 10}, 8);

    student.skaiciuoti_rezultata(2);

    EXPECT_DOUBLE_EQ(student.Rezultatas(), 8.4);
}

TEST(StudentasStreams, Nuskaitymas) {
    std::istringstream input("Tomas Tomaitis 10 9 0");
    Studentas student;

    input >> student;

    EXPECT_EQ(student.getVardas(), "Tomas");
    EXPECT_EQ(student.getPavarde(), "Tomaitis");
    EXPECT_EQ(student.getPaz(), std::vector<int>({10}));
    EXPECT_EQ(student.getEgz(), 9);
}

TEST(StudentasStreams, Isvedimas) {
    Studentas student = sukurtasStudentas("Laura", "Lauraitė", {10, 10}, 10);
    student.skaiciuoti_rezultata(1);

    std::ostringstream output;
    output << student;

    const std::string text = output.str();
    EXPECT_NE(text.find("Laura"), std::string::npos);//tikriname ar isvedime yra vardas, pavarde ir rezultatas
    EXPECT_NE(text.find("Lauraitė"), std::string::npos);
    EXPECT_NE(text.find("10.00"), std::string::npos);
}
