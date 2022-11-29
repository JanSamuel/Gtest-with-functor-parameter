# Gtest-with-functor-parameter
Code snipet of using function in gtest parametrized test

Idea which I got when writing repetitive tests for big class with only setter and getter and second one with interface between systems
It allowed to test tens of similiar methods with only one test so code got smaller and with much less work

Only downfall of such method is that object we want to test must be global in scope of test.
