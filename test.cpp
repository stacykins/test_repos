#include "pch.h"
#include "stringProcessor.h"
#include "sort.h"
#include <gtest/gtest.h>
#include <cstring>   // strcmp

TEST(QuickSortTest, SortsArrayInAscendingOrder) {
    char* arr[] = { "banana", "apple", "cherry", "date", "elderberry" };
    size_t length = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, length);

    for (size_t i = 1; i < length; i++) {
        ASSERT_TRUE(strcmp(arr[i - 1], arr[i]) <= 0);
    }
}

TEST(QuickSortTest, SingleElementArray) {
    char* arr[] = { "hello" };
    quick_sort(arr, 1);
    ASSERT_STREQ(arr[0], "hello");
}

TEST(QuickSortTest, SortedArray) {
    char* arr[] = { "alpha", "beta", "gamma" };
    quick_sort(arr, 3);
    ASSERT_STREQ(arr[0], "alpha");
    ASSERT_STREQ(arr[1], "beta");
    ASSERT_STREQ(arr[2], "gamma");
}

TEST(QuickSortTest, ReverseSortedArray) {
    char* arr[] = { "gamma", "beta", "alpha" };
    quick_sort(arr, 3);
    ASSERT_STREQ(arr[0], "alpha");
    ASSERT_STREQ(arr[1], "beta");
    ASSERT_STREQ(arr[2], "gamma");
}

TEST(QuickSortTest, RandomArray) {
    char* arr[] = { "hello", "world", "foo", "bar", "baz", "qux", "quux", "corge" };
    quick_sort(arr, 8);
    const char* expected[] = { "bar","baz","corge","foo","hello","quux","qux","world" };
    for (size_t i = 0; i < 8; i++) {
        ASSERT_STREQ(arr[i], expected[i]);
    }
}

TEST(StringProcessorTest, ValidString_ReturnsTrue) {
    char str[] = "Valid string: apple, banana; cherry";
    EXPECT_TRUE(is_string_valid(str));
}

TEST(StringProcessorTest, InvalidString_ReturnsFalse) {
    char str[] = "Invalid string: apple,; banana; cherry";
    EXPECT_FALSE(is_string_valid(str));
}

TEST(SwapTest, SwapsValuesCorrectly) {
    char* a = "apple";
    char* b = "banana";
    swap(&a, &b);
    EXPECT_STREQ(a, "banana");
    EXPECT_STREQ(b, "apple");
}
