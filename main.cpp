#include <iostream>
#include <string>

//#include "AudioBook.hpp"
//#include "Podcast.hpp"
//#include "Playlist.hpp"
//#include "Song.hpp"
//#include "PlaylistItem.hpp"
#include "DoublyLinkedList.hpp"

int main(){

   DoublyLinkedList<int> list;
   

   list.insert(1,1);
   list.insert(3,2);
   list.insert(6,3);
   list.insert(9,4);

   DoublyLinkedList<int> list2(list);

   list2.display();


   /*
   Song song1("girls", 4.22, "pop", "Drake"); 
   Song song2("boys", 3.15, "pop", "Drake");
   Song song3("feelings", 2.50, "pop", "Drake");

   Podcast podcast1("favorite murder", 30.22, "scary", "My Favorite Murder", "Daisy", "Toby");
   Podcast podcast2("bananas", 15.47, "fruit", "My Favorite Fruit", "Sam", "Jim");

   Playlist song_list;
   Playlist podcast_list;

   song_list.insert(&song1, 1);
   song_list.insert(&song2, 2);
   song_list.insert(&song2, 3);

   podcast_list.insert(&podcast1, 1);
   podcast_list.insert(&podcast2, 2);

   song_list.display();
   podcast_list.display();



   song_list+=podcast_list;


   song_list.display();
   */
 
}