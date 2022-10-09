add_test( [==[List::insertFront size]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::insertFront size]==]  )
set_tests_properties( [==[List::insertFront size]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::insertBack size]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::insertBack size]==]  )
set_tests_properties( [==[List::insertBack size]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::insert contents]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::insert contents]==]  )
set_tests_properties( [==[List::insert contents]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::triplerotate basic]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::triplerotate basic]==]  )
set_tests_properties( [==[List::triplerotate basic]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::triplerotate simple]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::triplerotate simple]==]  )
set_tests_properties( [==[List::triplerotate simple]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::split simple]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::split simple]==]  )
set_tests_properties( [==[List::split simple]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::split images]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::split images]==]  )
set_tests_properties( [==[List::split images]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::_destroy empty list]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::_destroy empty list]==]  )
set_tests_properties( [==[List::_destroy empty list]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::begin() returns an iterator to the front of the list]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::begin() returns an iterator to the front of the list]==]  )
set_tests_properties( [==[List::begin() returns an iterator to the front of the list]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::ListIterator::operator++ advances the iterator (pre-increment)]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::ListIterator::operator++ advances the iterator (pre-increment)]==]  )
set_tests_properties( [==[List::ListIterator::operator++ advances the iterator (pre-increment)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::ListIterator::operator++ advances the iterator (post-increment)]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::ListIterator::operator++ advances the iterator (post-increment)]==]  )
set_tests_properties( [==[List::ListIterator::operator++ advances the iterator (post-increment)]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::ListIterator::operator++ (post-increment) returns an un-incremented iterator]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::ListIterator::operator++ (post-increment) returns an un-incremented iterator]==]  )
set_tests_properties( [==[List::ListIterator::operator++ (post-increment) returns an un-incremented iterator]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::ListIterator::operator-- moves the iterator backwards]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::ListIterator::operator-- moves the iterator backwards]==]  )
set_tests_properties( [==[List::ListIterator::operator-- moves the iterator backwards]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::ListIterator::operator-- (post-increment) returns an un-incremented iterator]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::ListIterator::operator-- (post-increment) returns an un-incremented iterator]==]  )
set_tests_properties( [==[List::ListIterator::operator-- (post-increment) returns an un-incremented iterator]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::ListIterator::end is reached]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::ListIterator::end is reached]==]  )
set_tests_properties( [==[List::ListIterator::end is reached]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::ListIterator::end is not ::begin in a non-empty list]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::ListIterator::end is not ::begin in a non-empty list]==]  )
set_tests_properties( [==[List::ListIterator::end is not ::begin in a non-empty list]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( List::reverse /workspaces/cs225/mp_clean_lists/build/test List::reverse  )
set_tests_properties( List::reverse PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::reverseNth #1]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::reverseNth #1]==]  )
set_tests_properties( [==[List::reverseNth #1]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::reverseNth #2]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::reverseNth #2]==]  )
set_tests_properties( [==[List::reverseNth #2]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( List::merge /workspaces/cs225/mp_clean_lists/build/test List::merge  )
set_tests_properties( List::merge PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::sort simple #1]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::sort simple #1]==]  )
set_tests_properties( [==[List::sort simple #1]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::sort simple #2]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::sort simple #2]==]  )
set_tests_properties( [==[List::sort simple #2]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::sort #1]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::sort #1]==]  )
set_tests_properties( [==[List::sort #1]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[List::sort #2]==] /workspaces/cs225/mp_clean_lists/build/test [==[List::sort #2]==]  )
set_tests_properties( [==[List::sort #2]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
add_test( [==[Hello World]==] /workspaces/cs225/mp_clean_lists/build/test [==[Hello World]==]  )
set_tests_properties( [==[Hello World]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/mp_clean_lists/build)
set( test_TESTS [==[List::insertFront size]==] [==[List::insertBack size]==] [==[List::insert contents]==] [==[List::triplerotate basic]==] [==[List::triplerotate simple]==] [==[List::split simple]==] [==[List::split images]==] [==[List::_destroy empty list]==] [==[List::begin() returns an iterator to the front of the list]==] [==[List::ListIterator::operator++ advances the iterator (pre-increment)]==] [==[List::ListIterator::operator++ advances the iterator (post-increment)]==] [==[List::ListIterator::operator++ (post-increment) returns an un-incremented iterator]==] [==[List::ListIterator::operator-- moves the iterator backwards]==] [==[List::ListIterator::operator-- (post-increment) returns an un-incremented iterator]==] [==[List::ListIterator::end is reached]==] [==[List::ListIterator::end is not ::begin in a non-empty list]==] List::reverse [==[List::reverseNth #1]==] [==[List::reverseNth #2]==] List::merge [==[List::sort simple #1]==] [==[List::sort simple #2]==] [==[List::sort #1]==] [==[List::sort #2]==] [==[Hello World]==])
