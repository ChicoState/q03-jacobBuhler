/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}
TEST(GuesserTest, empty_guess)
{
  Guesser object("Secret");
  ASSERT_EQ( 0, 0);
}
TEST(GuesserTest, wrong_guess)
{
  Guesser object("Secret");
  object.match("Secrey");
  ASSERT_EQ( object.remaining(), 2);
}
TEST(GuesserTest, bruteforce_guess)
{
  Guesser object("Secret");
  object.match("ssssssss");
  ASSERT_FALSE(object.match("Secret"));
}
TEST(GuesserTest, long_guess)
{
  Guesser object("Secret");
  object.match("areallyreallylongpasswordthatiswayyyyyyylong");
  ASSERT_FALSE(object.match("Secret"));
}
TEST(GuesserTest, reset_guesses)
{
  Guesser object("Secret");
  object.match("Secreq");
  object.match("Secrew");
  object.match("Secret");
  ASSERT_EQ(object.remaining(), 3);
}
