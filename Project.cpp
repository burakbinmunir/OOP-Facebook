#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

class Helper;
class User;
class Page;
class Facebook;
class Comments;
class Post;
class Object;
class Date;
class Activity;


				/* W E L C O M  E _____ T O ______ B U R A K' S ___ F A C E B O O K */


// We will need the Helper class throughout the whole program
// so rather than declaring these functions in each class
// we will declare it in one class and will call in every class where needed
class Helper
{
public:

	// This function will return the length of given string
	static int StrLen(char* _string)
	{
		int _stringLength = NULL;

		for (int index = NULL; _string[index] != '\0'; index++)
			_stringLength++;

		return _stringLength;
	}

	// This function will return an array charaters from buffer
	static char* Buffer_To_String(char* buffer)
	{
		int bufferLength = StrLen(buffer); // counting length of buffer

		char* _string = new char[bufferLength + 1]; // extra space for storing the null character

		int index = NULL;

		for (; index < bufferLength; index++)
			_string[index] = buffer[index];

		_string[index] = '\0';

		return _string;
	}
	
	// This function will take two char arrays (ID) and will 
	// return true if both char arrays (Ids) will be same
	static bool Compare_ID(char* _id, char* _ID)
	{
		bool equal = false;
		int _idLength = StrLen(_id);
		int _IDLength = StrLen(_ID);

		// kept only one check because boths strings will
		// be same if there length would be same
		if (_idLength == _IDLength)
		{
			equal = false;
			for (int index = NULL; index < _idLength; index++)
			{
				equal = false;
				if (_id[index] == _ID[index])
				equal = true;
			}
		}
		
		return equal;
	}

	// This function will return a char array from 
	// string given as parameter
	static char* String_To_Char(string _string)
	{
		int _stringLength = _string.length(); // to find the length of string

		char* _charArray = new char[_stringLength + 1];// extra space for storing '\0' character
		
		int index = NULL;

		for (; index < _stringLength; index++)
				_charArray[index] = _string[index];

		_charArray[index] = '\0';

		return _charArray;
	}

	//This function will check either the input is -1 or not
	static bool Input_Not_minus1(char* buffer)
	{
		int counter = NULL;

		for (int p = 0; p < Helper::StrLen(buffer); p++)
		{
			if (buffer[p] == '-' || buffer[p] == '1')
				counter++;
		}

		if (counter != Helper::StrLen(buffer))
			return true;
		else
			return false;
	}

	// This function is use to deallocate the 1D array
	template<class D1>
	static void Deallocate_1D(D1*& _oneD)
	{
		delete[] _oneD;
		_oneD = NULL;		
	}

	// This function is use to deallocate the 2D array
	template<class D2>
	static void Deallocte_2D(D2**& _twoD, int size)
	{
		for (int index = NULL; index < size; index++)
		{
			delete _twoD[index];
			_twoD[index] = NULL;
		}

		delete[] _twoD;
		_twoD = NULL;
		size=NULL;
	}

	// This function will return true if substring will be found in mainstring
	static bool Search_Substring(char* mainString, char* subString)
	{
		int lengthOfLoop = Helper::StrLen(mainString);

		int check = NULL;
		bool found = false;
		int subString_Index = NULL;

		for (int index = NULL; index < lengthOfLoop; index++)
		{
			found = false;
			if (subString[subString_Index] == mainString[index] || subString[subString_Index] == (int (mainString[index])+32) || subString[subString_Index] == (int(mainString[index]) - 32))
			{
				check++;
				subString_Index++;
				found = true;
			}
			else
			{
				check = NULL;
				subString_Index =NULL;
				found = false;
			}

			if (check == Helper::StrLen(subString))
				return found;
		}
	} 

	static char* Concatenate(char* str1, char* str2)
	{
		str1, str2;
		int return_StringLength = NULL;
		if (StrLen(str1) > StrLen(str2))
		{
			return_StringLength = StrLen(str1);
		}
		else
			return_StringLength = StrLen(str2);

		char* return_string = new char[return_StringLength];
		int i;
		for (i = 0; str1[i] != '\0'; i++);


		for (int j = 0; str2[j] != '\0'; j++)
		{
			return_string[i] = str2[j];
			i++;
		}
		return_string[i] = '\0';

		return return_string;
	}
};

class Object
{
public:
	virtual void Print_Name_ID()
	{

	}

	virtual char* Get_ID()
	{
		return NULL;
	}

	virtual void Set_Post(Object*& objt)
	{

	}

	virtual void SharedBy(Object*)
	{

	}

	virtual ~Object()
	{
		
	}
};


/**************************************** D A T E  ****************************************************/
class Date
{
private:
	 int date;
	 int month;
	 int year;
public:
	// Deafult Constructor
	Date();

	// Current Date Object
	static Date currentDate;

	// Setting current Date
	static void Set_CurrentDate(int _d, int _m, int _y);

	// Printing Current Date
	static void Print_currentDate();
	
	// Geting Date
	Date Get_Date();
	
	// Inputing date by object of istream
	void InputDate(ifstream& _inputDate);

	// will return true if post will be posted within recent 24hours
	bool isDateLatest();

	// will set values of Date
	void Set_Values(int, int, int); 

	// will print the Date
	void Print_Date();
};

Date Date::currentDate;

Date::Date()
{
	date = NULL;
	month = NULL;
	year = NULL;
}

void Date::Set_CurrentDate(int _d, int _m, int _y)
{
	currentDate.date = _d;
	currentDate.month = _m;
	currentDate.year = _y;
}

void Date::Print_currentDate()
{
	cout << currentDate.date;
	cout << " / " << currentDate.month << " / " << currentDate.year << endl;
}

Date Date::Get_Date()
{
	return *this;
}

void Date::InputDate(ifstream& _inputDate)
{
	_inputDate >> date;
	_inputDate >> month;
	_inputDate >> year;
}

bool Date::isDateLatest()
{
	if (date == currentDate.date || date == currentDate.date - 1 && year == currentDate.year && month == currentDate.month)
		return true;
	else
		return false;
}

void Date::Set_Values(int _d, int _m, int _y)
{
	date = _d;
	month = _m;
	year = _y;
}

void Date::Print_Date()
{
	cout << date << "/ " << month << " / " << year;
}

/******************************************** C O M M E N T S *******************************************/

class Comments
{
private:
	Object* Author;// who commented
	char* text; // comment
	char* commet_ID; // comment ID

public:
	static int _totalComments;
	// Degault Constructor
	Comments();

	// Destructor
	~Comments();

	// Inputing ID and setting it
	void Set_ID(char*);

	// setting the ID of author
	// Author could be a page or user
	void Set_Author(Object* _id);

	// Setting comment text trough char*
	void Set_Comment_Text(char* _text);
	
	// Setting comment in case: inputing from file
	void Set_Comment(ifstream& input_commentData);	

	virtual void Print_Comment(); 
	
	void Give_New_ID()
	{
		_totalComments++;
		string tempID = "c" + to_string(_totalComments);
		commet_ID = Helper::String_To_Char(tempID);
	}

	// will return the text of comment
	char* Get_comment();	
};
int Comments::_totalComments = NULL;
Comments::Comments()
{
	commet_ID = NULL;
	Author = NULL;
	text = NULL;
}

Comments::~Comments()
{
	if (text)
		Helper::Deallocate_1D(text);

	if (commet_ID)
		Helper::Deallocate_1D(commet_ID);
}

void Comments::Set_ID(char* _id)
{
	commet_ID = Helper::Buffer_To_String(_id);
}

void Comments::Set_Author(Object* _id)
{
	Author = _id;
}

void Comments::Set_Comment_Text(char* _text)
{
	text = Helper::Buffer_To_String(_text);
}

void Comments::Set_Comment(ifstream& input_commentData)
{
	char buffer[100];
	input_commentData.getline(buffer, 100);

	text = Helper::Buffer_To_String(buffer);
}

void Comments::Print_Comment()
{
	cout << "\t\t\t\t\t";
	Author->Print_Name_ID();
	cout << " wrote: ";

	cout << text << endl;
}

char* Comments::Get_comment()
{
	return text;
}

/******************************************** P O S T S *******************************************/
class Post
{
protected:
	char* ID;	// ID of post
	char* caption;	// text of the post
	Date* dateShared;	// date on which the post was shared 

	Object* sharedBy;	// the page/user who shared
	Object** likedBy;	//	the pages / users who liked the post
	
	Comments** comments;	// comments on this->post
	int commentsOnPost;	// counter of comments on this->post

	int totalPosts;
	int totallikes;
public:

	Post();

	// Virtual because of Inherictance with activity class
	virtual ~Post();

	// will get the caption of Post
	virtual char* Get_PostCaption();
	
	// setting comments text along the author
	// we will need this to enter comment
	virtual void Set_comment(Object*, char*);

	void ViewLikedBy();

	Date Date_Shared();
	
	virtual void Print_Post();

	virtual void LoadFromFile(ifstream&);

	// In case : ppost shared by user
	//void SharedByUser(Object*);

	// In case: post shared by Page
	//void SharedBy(Object*);

	void Set_SharedBy(Object*);

	void LikeaPost(Object*);

	virtual Object* Get_SharedBy();
	
	// return ID of post
	char* Get_ID();
	
	// Association of comments with this->post
	void SetComment(Comments* comment);	
};

Post::Post()
{
	ID = NULL;
	caption = NULL;
	sharedBy = NULL;

	totallikes = NULL;
	totallikes = NULL;
	commentsOnPost = NULL;
	totalPosts = NULL;

	comments = new Comments * [20];
	likedBy = new Object * [20];
}

Post::~Post()
{
	if (ID)
		Helper::Deallocate_1D(ID);
	if (caption)
		Helper::Deallocate_1D(caption);
	if (comments)
		Helper::Deallocte_2D(comments, commentsOnPost);
	if (likedBy)
		Helper::Deallocate_1D(likedBy);

}

void Post::LoadFromFile(ifstream& input_PostData)
{
	char buffer[100];

	input_PostData >> buffer;
	ID = Helper::Buffer_To_String(buffer);

	
	dateShared = new Date;
	dateShared->InputDate(input_PostData);

	input_PostData.ignore();
	input_PostData.getline(buffer, 100);
	caption = Helper::Buffer_To_String(buffer);
}

void Post::Set_SharedBy(Object* _object)
{
	sharedBy = _object;
}

void Post::LikeaPost(Object* templikedby)
{
	likedBy[totallikes] = templikedby;
	totallikes++;
}

void Post::Print_Post()
{
	sharedBy->Print_Name_ID(); cout << " shared ";
	cout << " ' " << caption << " ' ";


	cout << ".....( ";
	dateShared->Print_Date();
	cout << " )";

	cout << endl;
	for (int index = NULL; index < commentsOnPost; index++)
	{
		comments[index]->Print_Comment();
		cout << endl;
	}

	cout << endl << endl;
}

Object* Post::Get_SharedBy()
{
	return sharedBy;
}

Date Post::Date_Shared()
{
	return dateShared->Get_Date();
}

void Post::ViewLikedBy()
{
	for (int index = NULL; index < totallikes; index++)
	{
		likedBy[index]->Print_Name_ID();
		cout << endl;
	}
}

void Post::SetComment(Comments* comment)
{
	comments[commentsOnPost] = comment;
	commentsOnPost++;
}

char* Post::Get_ID()
{
	return ID;
}

void Post::Set_comment(Object* commentBy, char* text)
{
	comments[commentsOnPost] = new Comments;
	comments[commentsOnPost]->Set_Author(commentBy);
	comments[commentsOnPost]->Set_Comment_Text(text);
	comments[commentsOnPost]->Give_New_ID();
	commentsOnPost++;
}

char* Post::Get_PostCaption()
{
	return caption;
}
/******************************************** A C T I V I T Y *******************************************/

class Activity :public Post
{
private:
	int type;
	char* value;
public:
	// Cosntructor
	Activity();

	// Destructor
	~Activity();

	void LoadFromFile(ifstream&);

	void SharedBy(Object* shared);
	
	// will return the date shared
	Date Date_Shared();

	void Print_Post();
	
	void Set_comment(Object*, char*);	

	Object* Get_SharedBy();

	char* Get_PostCaption();

	char* Get_ID();
};

Activity::Activity()
{
	type = NULL;
	value = NULL;
}

Activity::~Activity()
{
	if (value)
		Helper::Deallocate_1D(value);
}

void Activity::LoadFromFile(ifstream& input_PostData)
{
	Post::LoadFromFile(input_PostData);

	input_PostData >> type;

	char buffer[100];
	input_PostData.getline(buffer, 100);
	value = Helper::Buffer_To_String(buffer);
}

void Activity::SharedBy(Object* shared)
{
	sharedBy = shared;
}

Date Activity::Date_Shared()
{
	return dateShared->Get_Date();
}

void Activity::Set_comment(Object* commentBy, char* text)
{
	comments[commentsOnPost] = new Comments;
	comments[commentsOnPost]->Set_Author(commentBy);
	comments[commentsOnPost]->Set_Comment_Text(text);
	commentsOnPost++;
}

void Activity::Print_Post()
{
	sharedBy->Print_Name_ID();

	if (type == 1)
	{
		cout << " is feeling ";
		cout << value;
		cout << " ";
	}
	else
	{
		if (type == 2)
		{
			cout << " is thinking about ";
			cout << value;
			cout << " ";

		}
		else
		{
			if (type == 3)
			{
				cout << " is making ";
				cout << value << " ";
			}
			else
			{
				if (type == 4)
				{
					cout << " is celebrating ";
					cout << value << " ";
				}
			}
		}
	}

	cout << ".....( "; dateShared->Print_Date();
	cout << " )";

	cout << endl << " ' " << caption << " ' ";

	cout << endl << endl;

	for (int index = NULL; index < commentsOnPost; index++)
	{
		comments[index]->Print_Comment();
	}
	cout << endl << endl;
}

char* Activity::Get_ID()
{
	return value;
}

Object* Activity::Get_SharedBy()
{
	return sharedBy;
}

char* Activity::Get_PostCaption()
{
	return caption;
}

/******************************************** P A G E ************************************************/

class Page :public Object
{
private:
	char* ID;
	char* Title;
	Post** timeline; // every page has its own timeline of Posts
	int sharedPosts; // counter of shared posts

public:
	Page();

	~Page();

	// if the post will be latest it will show the post 
	// of recent 24 hours with forLastepost
	// else will print all posts of that page
	void Veiwtimeline(bool forLastepost);

	/// <summary>
	///  As the buffer takes all kind of input including
	/// '\t' or ' ' which might increase the length of string 
	/// which will be intialized from the length so this
	/// function will only count the required length
	/// </summary>
	static int StrLen(char*);

	// This function will read the data from the file
	// which contains the data of page i.e. their ID
	// title and will separate the spaces
	void ReadDataFromFile(ifstream&);

	void Set_Post(Post*& _post);
	
	char* Get_ID();

	char* Get_PageTitle();
	
	// This function will print the private attributes of Page class
	void Print_PageInfo(bool);

	void Print_Name_ID();	
};

Page::Page()
{
	ID = NULL;
	Title = NULL;
	sharedPosts = NULL;
	timeline = new Post*[20];
}

Page::~Page()
{
	if (ID)
		Helper::Deallocate_1D(ID);

	if (Title)
		Helper::Deallocate_1D(Title);

	if (timeline)
		Helper::Deallocte_2D(timeline, sharedPosts);
	
}

int Page::StrLen(char* _string)
{
	int _stringLength = NULL;

	for (int index = NULL; _string[index] != '\0'; index++)
	{
		if (_string[index] != '\t' && _string[index] != ' ')
			_stringLength++;
	}

	return _stringLength;
}

void Page::ReadDataFromFile(ifstream& input_PageData)
{
	char buffer[100];// it will take input till space

	input_PageData >> buffer;

	ID = Helper::Buffer_To_String(buffer); // this instruction will convert the buffer input into char array

	input_PageData.getline(buffer, 100); // this instruction will take whole line as input

	Title = Helper::Buffer_To_String(buffer);
}

char* Page::Get_ID()
{
	return ID;
}

void Page::Print_PageInfo(bool timelineVeiw)
{
	if (timelineVeiw == true)
	{
		if (ID && Title)
			cout << ID << " " << Title << endl;
		Veiwtimeline(false);
	}
	else
	{
		if (ID && Title)
			cout << ID << " " << Title << endl;
	}
}

void Page::Veiwtimeline(bool forLastepost)
{
	if (forLastepost == true)
	{
		for (int index = NULL; index < sharedPosts; index++)
		{
			Date _date = timeline[index]->Date_Shared();
			if (_date.isDateLatest() == true)
			{
				timeline[index]->Print_Post();
			}
		}
	}
	else
	{
		for (int index = NULL; index < sharedPosts; index++)
			timeline[index]->Print_Post();
	}
}

void Page::Set_Post(Post*& _post)
{
	timeline[sharedPosts] = _post;
	sharedPosts++;
}

char* Page::Get_PageTitle()
{
	return Title;
}

void Page::Print_Name_ID()
{
	cout << ID << "--";
	cout << Title;// << endl;
}

/******************************************** U S E R ************************************************/
class User :public Object
{
	char* ID;
	char* FirstName;
	char* LastName;
	User** FriendList;
	Page** LikedPages;
	Post** timeline;
	int sharedPosts;

public:

	int friends; // To keep the count of every user's friends   ( User at certain Index )
	int pages; // To keep the count of every user's liked pages ( User at certain Index )

	// Default Construtor 
	User();

	~User();

	void Set_Post(Post*& _post);
	
	void Veiwtimeline(bool forLatestPost);

	void Set_friend(int index, User*& _friend)
	{
			FriendList[index] = _friend;
	}

	void Set_page(int index, Page*& _page)
	{
		LikedPages[index] = _page;
	}

	// will show the timline of current user
	void Veiw_Home();
	
	void Set_UserID(char*);

	// This function will return the ID of *this ( i.e. current user in memory )
	char* Get_ID();
	
	void ReadDataFromFile(ifstream&, char***&, char***&, int);

	// This function will print the attributes of user in memory
	void Print_UserInfo();

	// This function will return the count of friends on the index given
	int Get_FriendsCount();

	// This function will return the count of liked pages on the index given
	int Get_PagesCount();

	// As friendList is public attribute so 
	// this function will print the info of friends (users)
	// by calling Print User Info fucntion
	void ViewFriendList();

	// As LikedPages is public attribute so 
	// this function will print the info of Pages
	// by calling Print Page Info fucntion of Page class
	void ViewLikedPages();

	void Print_Name_ID();
	
	char* Get_Firstname();

	char* Get_Lastname();
};

User::User()
{
	ID = NULL;

	FirstName = NULL;
	LastName = NULL;

	sharedPosts = NULL;
	FriendList = new User*[20];
	LikedPages = new Page * [20];
	timeline = new Post * [20];
}

void User::Set_UserID(char* _id)
{
	ID = _id;
}

char* User::Get_ID()
{
	return ID;
}

void User::ReadDataFromFile(ifstream& input_UserData, char***& tempFriendList, char***& tempLikedPages, int i_index)
{
	char buffer[100];
	input_UserData >> buffer;
	ID = Helper::Buffer_To_String(buffer);

	input_UserData >> buffer;
	FirstName = Helper::Buffer_To_String(buffer);

	input_UserData >> buffer;
	LastName = Helper::Buffer_To_String(buffer);

	// As tempFriendList is 3D pointer, we will store our Friend's List ( temp )
		// as 2D array on the ith index of tempFriendList
		//		2 3 4 1 2 3
		// u1   u u u p p p
		//        0   1
		//		1 1 1 1
		// u2   u u p p
		// .
		// .
		// .

	int j = 0;
	tempFriendList[i_index] = new char* [20];
	for (; j < 20; j++)
	{
		input_UserData >> buffer;
		if (Helper::Input_Not_minus1(buffer) == true)
			tempFriendList[i_index][j] = Helper::Buffer_To_String(buffer);
		else
		{
			friends = j;
			break;
		}
	}

	j = 0;
	tempLikedPages[i_index] = new char* [20];
	for (; j < 20; j++)
	{
		input_UserData >> buffer;

		if (Helper::Input_Not_minus1(buffer) == true)
			tempLikedPages[i_index][j] = Helper::Buffer_To_String(buffer);
		else
		{
			pages = j;
			break;
		}
	}
}

void User::Print_UserInfo()
{
	if (ID)
	cout << ID << " ";

	if (FirstName)
	cout << FirstName << " ";

	if(LastName)
	cout << LastName << " ";
}

int User::Get_FriendsCount()
{
	return friends;
}

int User::Get_PagesCount()
{
	return pages;
}

void User::ViewFriendList()
{
	//cout << FirstName << " " << LastName << "--Friend List\n\n";
	int index = NULL;

	while (index < friends)
	{
		FriendList[index]->Print_UserInfo();
		cout << endl;
		index++;
	}

	//for(; index < )
}

void User::ViewLikedPages()
{
	//	cout << FirstName << " " << LastName << "-- Liked Pages\n\n";
	int index = NULL;

	while (index < pages)
	{
		LikedPages[index]->Print_PageInfo(false);
		index++;
	}
}

void User::Set_Post(Post*& _post)
{
	timeline[sharedPosts] = _post;
	sharedPosts++;
}

void User::Print_Name_ID()
{
	cout << ID << "--";
	cout << FirstName << " " << LastName << " ";
}

char* User::Get_Firstname()
{
	return FirstName;
}

char* User::Get_Lastname()
{
	return LastName;
}

void User::Veiw_Home()
{
	int index = NULL;

	while (index< friends)
	{
		FriendList[index]->Veiwtimeline(true);
		index++;
	}

	index = NULL;

	while (index<pages)
	{
		LikedPages[index]->Veiwtimeline(true);
		index++;
	}
}

void User::Veiwtimeline(bool forLatestPost)
{
	if (forLatestPost == true)
	{
		for (int index = NULL; index < sharedPosts; index++)
		{
			Date _date = timeline[index]->Date_Shared();
			if (_date.isDateLatest() == true)
			{
				timeline[index]->Print_Post();
			}

		}
	}
	else
	{
		for (int index = NULL; index < sharedPosts; index++)
			timeline[index]->Print_Post();
	}
}

User::~User()
{
	if (ID)
		Helper::Deallocate_1D(ID);

	if (FirstName)
		Helper::Deallocate_1D(FirstName);

	if (LastName)
		Helper::Deallocate_1D(LastName);

	if (FriendList)
		Helper::Deallocate_1D(FriendList);

	if (LikedPages)
		Helper::Deallocate_1D(LikedPages);

	if (timeline)
		Helper::Deallocte_2D(timeline,sharedPosts);
}


/**************************************** F A C E B O O K ************************************************/

class Facebook
{
	// The 2D array of friends stored on the i_index of 3D tempFriendList
	// will be associated by this UserList because those friends are also users
	// of facebook so they will be associated 
	User** UsersList; 
	int totalUsers; // count of users

	// The 2D array of Pages stored on the i_index of 3D tempLikedPages
	// will be associated by this PageList because those pages are also 
	// liked by other users
	Page** PageList;
	int totalPages; // count of Pages

	Post** Posts;
	int totalPosts;	

	Comments** comment;
	int totalComments;

	static Date _currentDate;
	User* CurrentUser;
public:

	Facebook()
	{
		UsersList = new User*();
	}

	void Set_totalUsers(int);

	// This function will be given a ID and it will 
	// search the ID and will return the page index 
	// where it found ID
	Page* SearchPageByID(char []);
	
	// This function will be given an ID and it will
	// search the ID and will retrun the Userslist index
	// where the given ID is found
	User* SearchUserByID(char[]);

	// This function will load the data on each index of
	// 3D tempFriendList &&  tempLikedPages array
	void LoadData(char***&, char***&);

	// This function will first initialize the space of friends of user in memory
	// It will find the ID on the current index and
	// will put it on the index of FriendList along
	// with attributes of User class
	void AssociateFriends(char***&);

	void AssociatePages(char***&);
	
	//void associateposts
	// This function will get ID and will find the user by id
	// and will set that user as current user
	User* Set_CurrentUser(string);

	void Print_Info();

	void LaodFrom_CommentFile();

	void LaodPosts();

	Post* SearchPostByID(char* _id);

	void Print_Post()
	{
		for (int index = NULL; index < totalPosts; index++)
		{
			Posts[index]->Print_Post();
			cout << endl;
			cout << endl;
			comment[index]->Print_Comment();
			cout << endl << endl<<endl<<endl<<endl;
		}
	}

	void Veiwtimeline()
	{
		for (int index = NULL; index < totalUsers; index++)
		{
			UsersList[index]->Veiwtimeline(false);
		}
	}

	User** GetFriends()
	{
		return UsersList;
	}

	// will take a keyword and search page/user/ post
	void Search(char* keyWord)
	{
		bool foundUser = false;

		// Search from first or last name
		cout << endl << endl;
		cout << "Users: \n\n";
		for (int index = NULL; index < totalUsers; index++)
		{
			foundUser = false;

			char* firstname = UsersList[index]->Get_Firstname();
			char* lastname = UsersList[index]->Get_Lastname();

			if (Helper::StrLen(keyWord) > Helper::StrLen(firstname))
				foundUser = Helper::Search_Substring(keyWord, firstname);
			else
				foundUser = Helper::Search_Substring(firstname, keyWord);

			if (foundUser == true)
			{
				char* foundsuer_ID = UsersList[index]->Get_ID();
				User* _foundUser = SearchUserByID(foundsuer_ID);
				_foundUser->Print_UserInfo();
				cout << endl;
			}

			if (Helper::StrLen(keyWord) > Helper::StrLen(lastname))
				foundUser = Helper::Search_Substring(keyWord, lastname);
			else
				foundUser = Helper::Search_Substring(lastname, keyWord);

			if (foundUser == true)
			{
				char* foundsuer_ID = UsersList[index]->Get_ID();
				User* _foundUser = SearchUserByID(foundsuer_ID);
				_foundUser->Print_UserInfo();
				cout << endl;
			}
		}

		// Search From Pages
		cout << endl << endl;
		cout << "Pages: \n\n";
		bool found_Page = false;
		for (int index = NULL; index < totalPages; index++)
		{
			found_Page = false;
			char* page_Title = PageList[index]->Get_PageTitle();

			if (Helper::StrLen(page_Title) > Helper::StrLen(keyWord))
				found_Page = Helper::Search_Substring(page_Title, keyWord);
			else
				found_Page = Helper::Search_Substring(keyWord, page_Title);

			if (found_Page == true)
			{
				char* _pageID = PageList[index]->Get_ID();
				Page* _foundPage = SearchPageByID(_pageID);
				_foundPage->Print_PageInfo(true);
				cout << endl;
			}
		}

		cout << endl << endl;
		// Search from Post
		cout << "Posts: \n\n";
		bool found_Post = false;
		for (int index = NULL; index < totalPosts; index++)
		{
			found_Post = false;
			char* _caption = Posts[index]->Get_PostCaption();

			if (Helper::StrLen(_caption) > Helper::StrLen(keyWord))
				found_Post = Helper::Search_Substring(_caption, keyWord);
			else
				found_Post = Helper::Search_Substring(keyWord, _caption);

			if (found_Post == true)
			{
				char* _postID = Posts[index]->Get_ID();

				Post* _post = SearchPostByID(_postID);
				_post->Print_Post();
				cout << endl;
			}
		}
	
	}

	// to run the all fucntions
	void Run()
	{	
		cout << "Command:\tView Friend List\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		CurrentUser->Print_Name_ID();	cout << "--Friend List\n\n";
		//View Friendlist
		CurrentUser->ViewFriendList();
		cout << endl << endl;

		cout << "Command:\tView Liked Pages\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		CurrentUser->Print_Name_ID();	cout << "--Liked Pages\n\n";
		// View Liked Pages
		CurrentUser->ViewLikedPages();
		cout << endl << endl;


		cout << "Command:\tView Home\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		CurrentUser->Print_Name_ID();	cout << "--Home Page\n\n";
		//Veiw Home
		char* id;
		User* user;
		CurrentUser->Veiw_Home();
		cout << endl << endl;


		cout << "Command:\tView Time Line\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		CurrentUser->Print_Name_ID();	cout << "--Time Line\n\n";
		// View timeline
		CurrentUser->Veiwtimeline(false);
		cout << endl << endl;

		cout << "Command:\tView Liked List (Post5)\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		id = Helper::String_To_Char("post5");
		Post* _post = SearchPostByID(id);
		_post->ViewLikedBy();
		cout << endl << endl;

		cout << "Command:\t Like a Post (Post5)\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		//Like a Post
		id = Helper::String_To_Char("post5");
		_post = SearchPostByID(id);
		user = CurrentUser;
		_post->LikeaPost(user);
		cout << endl << endl;

		cout << "Command:\t View Liked List (Post5)\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		_post->ViewLikedBy();
		cout << endl << endl;

		cout << "Command:\t Post Comment (post4,Good Luck for your Result\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		id = Helper::String_To_Char("post4");
		_post = SearchPostByID(id);
		char* text = Helper::String_To_Char("Good Luck for your Result");
		_post->Set_comment(SearchUserByID(CurrentUser->Get_ID()), text);
		cout << endl << endl;

		cout << "Command:\t Veiw Post (post4)\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		id = Helper::String_To_Char("post4");
		_post = SearchPostByID(id);
		_post->Print_Post();
		cout << endl << endl;

		cout << "Command:\t Post Comment (post8,Thanks for Wishes\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		id = Helper::String_To_Char("post8");
		_post = SearchPostByID(id);
		text = Helper::String_To_Char("Thanks for wishes");
		_post->Set_comment(SearchUserByID(CurrentUser->Get_ID()), text);
		cout << endl << endl;

		cout << "Command:\t Veiw Post (post8)\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		id = Helper::String_To_Char("post8");
		_post = SearchPostByID(id);
		_post->Print_Post();
		cout << endl << endl;

		cout << "Command:\t Veiw Page (Page 1)\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		// Veiw Page
		id = Helper::String_To_Char("p1");
		Page* _page = SearchPageByID(id);
		_page->Print_PageInfo(true);
		cout << endl << endl;

		cout << "command:\t Search ( Ali ) \n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		char* word = Helper::String_To_Char("Ali");
		Search(word);
		cout << endl << endl;

		cout << "command:\t Search ( Birthday ) \n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		word = Helper::String_To_Char("Birthday");
		Search(word);		
	}

	~Facebook();
};

Page* Facebook::SearchPageByID(char _id[5])
{
	// This function will use Compare_ID function
	// if the IDs would match it will return the index
	for (int index = 0; index < totalPages; index++)
	{
		if (Helper::Compare_ID(_id, PageList[index]->Get_ID()) == true)
			return PageList[index];
	}
}

User* Facebook::SearchUserByID(char _id[5])
{
	for (int index = 0; index < totalUsers; index++)
	{
		// This function will use Compare_ID function
		// if the IDs would match it will return the index
		if (Helper::Compare_ID(_id, UsersList[index]->Get_ID()) == true)
			return UsersList[index];
	}
	
}

void Facebook::Set_totalUsers(int user)
{
	totalUsers = user;
}

void Facebook::LoadData(char***& tempFriendList, char***& tempLikedPages)
{
	// Reading User Data
	ifstream input_UserData("Friendslist.txt");

	if (input_UserData.is_open())
	{
		input_UserData >> totalUsers;
		Set_totalUsers(totalUsers);
		UsersList = new User * [totalUsers]; // Initializing User type object on each row

		tempFriendList = new char** [totalUsers];
		tempLikedPages = new char** [totalUsers];

		for (int index = NULL; index < totalUsers; index++)
		{
			UsersList[index] = new User; // Intialize User object on column

			UsersList[index]->ReadDataFromFile(input_UserData, tempFriendList, tempLikedPages, index);
		}

	}

	input_UserData.close();

	ifstream input_PageData("PageList.txt");

	if (input_PageData.is_open())
	{
		input_PageData >> totalPages;

		PageList = new Page * [totalPages];// Initilizing Page object on each row}

		for (int index = NULL; index < totalPages; index++)
		{
			PageList[index] = new Page; // Initializing Page object on each column

			PageList[index]->ReadDataFromFile(input_PageData);
		}
	}

	input_PageData.close();
}

void Facebook::LaodFrom_CommentFile()
{
	ifstream input_CommentData("Comments.txt");

	if (input_CommentData.is_open())
	{
		input_CommentData >> totalComments;
		Comments::_totalComments = totalComments;

		comment = new Comments * [totalComments];

		for (int index = NULL; index < totalComments; index++)
		{
			comment[index] = new Comments;
			char buffer[100];

			// Setting comment ID
			input_CommentData >> buffer;
			char* _id = Helper::Buffer_To_String(buffer);
			comment[index]->Set_ID(_id);

			// Searching for Post on which comment has been placed
			input_CommentData >> buffer;
			char* tempID = Helper::Buffer_To_String(buffer);

			// Setting the comment on the particular post ( Association )
			Post* _post = SearchPostByID(tempID);
			_post->SetComment(comment[index]);

			//Setting the ID of Author 
			input_CommentData >> buffer;
			_id = Helper::Buffer_To_String(buffer);
			if (buffer[0] == 'p')
			{
				comment[index]->Set_Author(SearchPageByID(_id));
			}

			if (buffer[0] == 'u')
			{
				//_id = Helper::Buffer_To_String(buffer);
				comment[index]->Set_Author(SearchUserByID(_id));
			}

			// Setting the text of Comment
			comment[index]->Set_Comment(input_CommentData);

		}
	}

	input_CommentData.close();
}

void Facebook::AssociateFriends(char***& tempFriendList)
{
 	for (int index = NULL; index < totalUsers; index++)
	{
		int _friends = UsersList[index]->Get_FriendsCount();	


		for (int j_index = NULL; j_index < _friends; j_index++)
		{
			User* _user = SearchUserByID(tempFriendList[index][j_index]);
			UsersList[index]->Set_friend(j_index, _user);
		}
	}


	 //Deletion of Useless array
	for (int i_index = NULL; i_index < totalUsers; i_index++)
	{
		int friends = UsersList[i_index]->Get_FriendsCount();// Will get the friend count 

		for (int i = 0; i < friends; i++)
		{
			delete tempFriendList[i_index][i];
			tempFriendList[i_index][i] = NULL;
		}
		delete tempFriendList[i_index];
		tempFriendList[i_index] = NULL;
	}
	delete[] tempFriendList;
	tempFriendList = NULL;

}

User* Facebook::Set_CurrentUser(string _id)
{
	char* _iD = Helper::String_To_Char("u3");// This will convert string into char* array

	CurrentUser = SearchUserByID(_iD);
	cout << "\t\t\t";

	return CurrentUser;
}

void Facebook::Print_Info()
{
	for (int i = 0; i < totalUsers; i++)
	{
		UsersList[i]->Print_UserInfo();
		cout << endl;
	}

	cout << endl << endl;

	for (int j = 0; j < totalPages; j++)
	{
		PageList[j]->Print_PageInfo(false);
		cout << endl;
	}
}

void Facebook::AssociatePages(char***& tempLikedPages)
{
	int pages;

	for (int index = NULL; index < totalPages; index++)
	{
		pages = UsersList[index]->Get_PagesCount();

		for (int j_index = NULL; j_index < pages; j_index++)
		{
			Page* _page = SearchPageByID(tempLikedPages[index][j_index]);
			UsersList[index]->Set_page(j_index, _page);
		}
	}


	// Deletion of Useless array
	for (int i_index = NULL; i_index < totalUsers; i_index++)
	{
		pages = UsersList[i_index]->Get_PagesCount();// will get Pages count

		for (int i = 0; i < pages; i++)
		{
			delete tempLikedPages[i_index][i];
			tempLikedPages[i_index][i] = NULL;
		}
		delete tempLikedPages[i_index];
		tempLikedPages[i_index] = NULL;
	}
	delete[] tempLikedPages;
	tempLikedPages = NULL;
}

void Facebook::LaodPosts()
{
	ifstream input_PostData("Posts.txt");

	if (input_PostData.is_open())
	{
		input_PostData >> totalPosts;

		Posts = new Post * [totalPosts];

		char buffer[100];
		Object* tempsharedBy = new Object[1];
		for (int index = NULL; index < totalPosts; index++)
		{
			input_PostData >> buffer;


			Object** templikedBy = new Object * [20];

			if (buffer[0] == '1')
			{
				Posts[index] = new Post;
			}
			if (buffer[0] == '2')
			{
				Posts[index] = new Activity;
			}
			Posts[index]->LoadFromFile(input_PostData);

			input_PostData >> buffer;
			if (buffer[0] == 'u')
				tempsharedBy = SearchUserByID(buffer);
			else
				if (buffer[0] == 'p')
					tempsharedBy = SearchPageByID(buffer);

			Posts[index]->Set_SharedBy(tempsharedBy);

			for (int i = 0; i < 20; i++)
			{
				input_PostData >> buffer;

				if (Helper::Input_Not_minus1(buffer) == true)
				{
					if (buffer[0] == 'u')
					{
						templikedBy[index] = SearchUserByID(buffer);
						Posts[index]->LikeaPost(templikedBy[index]);
					}
					else
					{
						if (buffer[0] == 'p')
						{
							templikedBy[index] = SearchPageByID(buffer);
							Posts[index]->LikeaPost(templikedBy[index]);
						}
					}
				}
				else
				{
					break;
				}
			}
		}
		input_PostData.close();
	}
}

Post* Facebook::SearchPostByID(char _id[10])
{
	for (int index = 0; index < totalPosts; index++)
	{
		if (Helper::Compare_ID(_id, Posts[index]->Get_ID()) == true)
			return Posts[index];
	}
}

Facebook::~Facebook()
{
	Helper::Deallocte_2D(UsersList, totalUsers);
	Helper::Deallocte_2D(PageList, totalPages);
	Helper::Deallocate_1D(Posts);
}

/******************************************** M A I N ************************************************/

void main()
{
	system("color F0");

	cout << "\t\t\t\t\t\t\t WELCOME TO BURAK'S FACEBOOK\n\n\n";

	Date::Set_CurrentDate(15, 11, 2017);

	Facebook fb;

	char*** tempFriendList;
	char*** tempLikedPages;

	fb.LoadData(tempFriendList, tempLikedPages);

	fb.AssociateFriends(tempFriendList);
	fb.AssociatePages(tempLikedPages);

	fb.LaodPosts();
	fb.LaodFrom_CommentFile();

	cout << "Command:\tSet Current user 'u7'\n";
	User* _currentUser = fb.Set_CurrentUser("u1");
	_currentUser->Print_Name_ID(); cout << "Successfully set as Current User\n";
	cout << endl;

	cout << "Command:\tSet system Date 15 11 2017\n";
	cout << "System Date:\t";
	Date::Print_currentDate();
	
	fb.Run();
	
	system("pause");
}
