// Count the number of Duplicates
// Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

// Example
// "abcde" -> 0 # no characters repeats more than once
// "aabbcde" -> 2 # 'a' and 'b'
// "aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
// "indivisibility" -> 1 # 'i' occurs six times
// "Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
// "aA11" -> 2 # 'a' and '1'
// "ABBA" -> 2 # 'A' and 'B' each occur twice

function duplicateCount(text) {
    let chars = text.toLowerCase().split('');
    let numberOfDuplicates = 0;
    let duplicates = new Object();
    for (let i in chars) {
        if (!duplicates[chars[i]]) {
            duplicates[chars[i]] = 1;
        } else {
            duplicates[chars[i]] += 1;
        }
    }
    for (let prop in duplicates) {
        if (duplicates[prop] > 1) {
            numberOfDuplicates++;
        }
    }
    return numberOfDuplicates;
}