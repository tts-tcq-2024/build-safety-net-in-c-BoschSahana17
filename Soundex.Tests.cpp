#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, Empty) {
    char soundex[5];
    generateSoundex("", soundex);
   }

TEST(SoundexTestsuite, SingleCharacter) {
    char soundex[5];
    generateSoundex("S", soundex);
    }

TEST(SoundexTestsuite, digit) {
    char soundex[5];
    generateSoundex("4", soundex);
    }

TEST(SoundexTestsuite, Name) {
    char soundex[5];
    generateSoundex("Sahana", soundex);
}

TEST(SoundexTestsuite, MixedCasealphabate) {
    char soundex[5];
    generateSoundex("SaHaNa", soundex);
}

TEST(SoundexTestsuite, LowercaseCharacter) {
    char soundex[5];
    generateSoundex("anjali", soundex);
}

TEST(SoundexTestsuite, RepeatedConsonants) {
    char soundex[5];
    generateSoundex("AABB", soundex);
}

TEST(SoundexTestsuite, ConsecutiveIdenticalConsonants) {
    char soundex[5];
    generateSoundex("AABBB", soundex);
}

TEST(SoundexTestsuite, NonAlphabeticCharacters) {
    char soundex[5];
    generateSoundex("A1B2C", soundex);
}

TEST(SoundexTestsuite, SpecialCharacters) {
    char soundex[5];
    generateSoundex("Anj@123", soundex);
    }

TEST(SoundexTestsuite, NameWithVowels) {
    char soundex[5];
    generateSoundex("seoul", soundex);
}

TEST(SoundexTestsuite, ShortName) {
    char soundex[5];
    generateSoundex("jai", soundex);
 }

TEST(SoundexTestsuite, LongName) {
    char soundex[5];
    generateSoundex("Harikrishnan", soundex);
}

TEST(SoundexTestsuite, LongSequenceOfSameConsonants) {
    char soundex[5];
    generateSoundex("JJJJJJJJJJJJ", soundex);
}

TEST(SoundexTestsuite, NullInputSoundexArray) {
    generateSoundex("Sahana", NULL);
}

TEST(SoundexTestsuite, NullInputName) {
    char soundex[5];
    generateSoundex(NULL, soundex);
}
