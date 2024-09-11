#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '1', '2', '0', '5', '0', '0', '1', '0', '2', '0', '3', '0', '1', '0', '2', '0', '2'
    };

    c = toupper(c); // Convert character to uppercase
    return (c >= 'A' && c <= 'Z') ? soundexTable[c - 'A'] : '0';
}

// Function to initialize the Soundex string with the first character
void initializeSoundex(char *soundex, char initialChar) {
    soundex[0] = toupper(initialChar);
    for (int i = 1; i < 4; i++) {
        soundex[i] = '0';
    }
    soundex[4] = '\0'; // Null-terminate the string
}

// Function to update Soundex code based on subsequent characters
void updateSoundex(char *soundex, const char *name) {
    int sIndex = 1; // Start after the initial character
    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }
}

// Main function to generate the Soundex code from the given name
void generateSoundex(const char *name, char *soundex) {
    if (name == NULL || soundex == NULL) return;
    
    int len = strlen(name);
    if (len == 0) {
        initializeSoundex(soundex, ' '); // Empty name
        return;
    }
    
    initializeSoundex(soundex, name[0]); // Initialize with the first character
    updateSoundex(soundex, name); // Update the Soundex code based on the rest of the name
}

#endif // SOUNDEX_H
