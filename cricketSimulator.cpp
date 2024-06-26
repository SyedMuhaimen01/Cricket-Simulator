#include<iostream>
#include<fstream>
#include<ctime>
#include<iomanip>

using namespace std;

int count=0;
int get_overs(int& count);
int toss(int &t);
int Score(int p_score[11],char team1[][15],char team2[][15],int i,int &overs,int &wickets,int &team_s,int &ov,int &balls_over,int &a);
void batting();

void drawScoreCard( int &score, float &balls,int player_balls[11],int p_score[11],int fours_team1[11], int six_team1[11],float Sr_team1[11],char team1[][15],int i,int &wickets,int &teams,int &ov,int &balls_over,int &ove,char team2[][15]);
void team_score(int p_score[11],int &score,float &balls,int &wicket,int i,int &team_s,int &ov,int &balls_over,int &ove);
float run_rate(int &team_s, float &balls);
string batsman(char team1[][15],int i);
void baller_card(char team2[][15],int p_score[11],int &ove);
void innings1(int &score, float &balls,int player_balls[11],int p_score[11],int fours_team1[11], int six_team1[11],float Sr_team1[11],char team1[][15],int i,int &wickets,int &team_s,int &ov,int &balls_over);

string MoM(char team1[][15],int p_score[11]);


//----------------------------------------------------------------------------------------------------------
int Score_team2(int p_score_team2[11],char team1[][15],char team2[][15],int m,int &ove2,int &wickets_team2,int &team2_s,int &ov2,int &balls_over2,int &q,int count2,int j);
void drawScoreCard_team2( int &score,float &balls,int player_balls_team2[11], int p_score_team2[11],int fours_team2[11],int six_team2[11],float Sr_team2[11], char team2[][15],int m,int &wickets_team2,int &team2_s,int &ov2,int &balls_over2,int &ove2,char team1[][15],int j);
void team2_score(int p_score_team2[11],int &score,float &balls2,int &wicket_team2,int m,int &team2_s,int &ov2,int &balls_over2,int &ove2);
void baller_card2(char team1[][15],int n,int p_score_team2[11],int &ove2);
void innings2(int &score2, float &balls,int player_balls_team2[11],int p_score_team2[11],int fours_team2[11], int six_team2[11],float Sr_team2[11],char team2[][15],int i,int &wickets_team2,int &team2_s,int &ov2,int &balls_over2,int &ove2);
float run_rate_team2(int &team2_s, float &balls2);
string batsman_team2(char team2[][15],int m);
string MoM2(char team2[][15],int p_score[11]);

void result(int &team_s,int &team2_s,char team1[][15],char team2[][15],int p_score[11],int p_score_team2[11]) ;

int main()
{
	int i=0,wickets=0,team_s=0,ove;
	int balls_over=0,ov=0;
	int balls_over2=0,ov2=0;
	int count2=1;
	int a=1;
	int j=10;
//	int p_score[11]={0};
//	int p_score_team2[11]={0};
	//------------
	
	int m=0,wickets_team2=0,team2_s=0,ove2=0;
	
	int q=1;
	int n=10;
	srand(time(NULL));
	ove=get_overs(count);
	ove2=ove;
	
	char team1[11][15];
        char team2[11][15];
         // taking input names of team 1 players 
        cout<<"Enter names of Players of Team 1 :"<<endl;
        cout<<endl;
        for(int i=0 ;i<11 ;i++ )
        {
        	cout<<i+1<<" ";
		cin>>("%s",&team1[i][0]);
        }
        cout<<endl;
         // taking input names of team 2 players 
         
        cout<<"Enter names of Players of Team 2 :"<<endl;
         for(int i=0 ;i<11 ;i++ )
        {
        	cout<<i+1<<" ";
		cin>>("%s",&team2[i][0]);
        }         
       
      // clearing screen
	cin.ignore();
	cout<<"Press Enter to continue "<<endl;
	cin.get();
	system("clear");
	
	// displaying team 1 players
	cout<<"______________________________"<<endl;
	cout<<endl;
	cout<<"\tPAKISTAN "<<endl;
	cout<<"______________________________"<<endl;
	cout<<endl;
	for(int i=0 ;i<11 ;i++)
        {
		cout<<" "<<i+1<<" "<<("%s\n",team1[i]);
		cout<<endl;
	}
	cout<<"______________________________"<<endl;
	cout<<endl;
	
	cout<<"______________________________"<<endl;
	cout<<endl;
	cout<<"\tKACHRA 11 "<<endl;
	cout<<"______________________________"<<endl;
	cout<<endl;
	// displaying team 2 players
	
    
        for(int i=0 ;i<11 ;i++)
        {
		cout<<" "<<i+1<<" "<<("%s\n",team2[i]);
		cout<<endl;
	}
	cout<<"______________________________"<<endl;
	cout<<endl;
	// clearing window
	cin.ignore();
	cout<<"Press Enter to continue "<<endl;
	cin.get();
	system("clear");
	//------------------------------------------------------------------------
	//dynamically creating 1 d arrays
	
	int* p_score= NULL;          
	p_score = new int[11];  
	for (int i=0; i<11; i++)
	{
	    p_score[i] = 0;    
	}

	int* p_score_team2= NULL;          
	p_score_team2 = new int[11];  
	for (int m=0; m<11; m++)
	{
	    p_score_team2[m] = 0;    
	}
	// implementing logic for the toss winner to bat
	int t;
	int Toss;
	cout<<"Heads or Tails"<<endl;
	cout<<"Press '1'for  Heads and '2' for Tails "<<endl;
	cin>>t;
	while(t != 1 && t!= 2)
	{
		cout<<"Invalid Input. Please try again"<<endl;
		cin>>t;
	}
	
	Toss=toss(t);
	if(Toss==t)
	{
		Score(p_score,team1,team2,i,ove,wickets,team_s,ov,balls_over,a);
		Score_team2(p_score_team2,team1,team2,i,ove2,wickets_team2,team2_s,ov2,balls_over,a,count2,j);
	}
	else
	{
		Score_team2(p_score_team2,team1,team2,i,ove2,wickets_team2,team2_s,ov2,balls_over,a,count2,j);
		Score(p_score,team1,team2,i,ove,wickets,team_s,ov,balls_over,a);
	}
	
	
	//---------------------------------------------------
	
	
	result(team_s,team2_s,team1,team2,p_score,p_score_team2);
	//deleting the dynamically created arrays
	delete [] p_score;
	delete [] p_score_team2;  
	p_score = NULL;
	p_score_team2 = NULL;
}

int get_overs(int& count)
{	
	
	 int overs; 
	 if(count==0)
	 {
	 	cout<<"Enter number of overs: "<<endl;
	 	cin>>overs;
	 	// writing overs in file
	 	
	 	ofstream file("configuration.txt");
	 	file<<"Overs : "<<overs<<endl;
	 	file.close();
	 	cout<<endl;
	 
	 	// reading overs from file 
	 
	 	ifstream File("configuration.txt");
	 	cout<<"Overs : "<<overs<<endl;
	 	//clearing window
	 	cin.ignore();
	 	cout<<"Press Enter to continue "<<endl;
		cin.get();
	}
	count++;
	system("clear");
	int total_balls;
	total_balls=overs*6;
	 return total_balls;
}

			//Toss
int toss(int &t)
{
	// generating random result of toss
	int n;
	
	n=(rand()%2)+1;
	if(n==t)
	{
		cout<<"Pakistan won the toss and will bat first "<<endl;
	}
	else
	{
		cout<<"Kachra 11 won the toss and wil bat first "<<endl;
	}
	cin.ignore();
	cout<<"Press Enter to continue "<<endl;
	cin.get();
	system("clear");
	return n ;
}
			//Score
int Score(int p_score[11],char team1[][15],char team2[][15],int i,int &ove,int &wickets,int &team_s,int &ov,int &balls_over,int &a)
{
	

//---------------------------------------------------------------------------------------------------------------------

	//int p_score[11]={0};
	int fours_team1[11]={0};
	int six_team1[11]={0};
	int player_balls[11]={0};
	int count=1;
	int player_balls_count=1;
	int count_balls=1;
	float balls=0;
	srand(time(NULL));
	int score = 0;
	int innings_balls=ove;
	float Sr_team1[11]={0};
	float total_score = 0;
	int F=0,S=0;
	// condition to implement innings within standard boundaries
	
	while (wickets!=10 && innings_balls!=0)
	{
		if(score<0)
		{
			p_score[i]=p_score[i]-score;
			i++;
			wickets++;
			total_score=0;
			F=0;
			S=0;
			player_balls_count=1;
			count_balls=1;
			
		}
	/*	if(score ==1 || score==3 || score==5 || count%6==0)
		{
			if (a%2 ==0)
			{
				i--;
				a++;
			}
			else
			{
				i++;
				a++;
			}
			
			player_balls[i]=count_balls;
			count_balls++;
		}
		else
		{*/
		player_balls[i]=player_balls_count;
			player_balls_count++;
	//	}
		balls=count;
		if(wickets <=6)
		{
			score = (rand()%8) - 1;
		}
		else
		{
			score= (rand() % 14)-8  ;
		
			//counting sixes and fours
		}
		if(score == 4)
		{
			F++;
		}
		if (score == 6)
		{
			S++;
		}
		fours_team1[i]=F;
		six_team1[i]=S;
		
		
		count++;
	
		total_score += score;
		p_score[i]+=score;
		Sr_team1[i]= (p_score[i]/balls)*100;
		drawScoreCard(score,balls,player_balls,p_score,fours_team1,six_team1,Sr_team1, team1,i,wickets,team_s,ov,balls_over,ove,team2);
		cin.get();
		system("clear");
		innings_balls--;
		
		
		
	
	}
	drawScoreCard(score,balls,player_balls,p_score,fours_team1,six_team1,Sr_team1, team1,i,wickets,team_s,ov,balls_over,ove,team2);
	baller_card(team2,p_score,ove);
	innings1(score,balls,player_balls, p_score,fours_team1, six_team1, Sr_team1, team1, i,wickets,team_s,ov,balls_over);

	return 0;	

}
void drawScoreCard( int &score,float &balls,int player_balls[11], int p_score[11],int fours_team1[11],int six_team1[11],float Sr_team1[11], char team1[][15],int i,int &wickets,int &team_s,int &ov,int &balls_over,int &ove,char team2[][15])
{
//displaying the batting and ballling card
	int b=player_balls[i];
	int four=0,six=0;
	float Sr=0;
	int t_balls;
	string bat;
	int to_score=p_score[i];
	four=fours_team1[i];
	six=six_team1[i];
	Sr=Sr_team1[i];
	if(wickets!=10 || ove!=0)
	{
	cout<<"\t\t\t\tPAKISTAN"<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"BATTING"<<"\t\t\t\t"<<" R"<<" \t\t"<<" B"<<"\t"<<"4s"<<"\t"<<"6s"<<"\t"<<"SR"<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;


		bat=	batsman(team1,i);
		
		cout<<bat<<"\t\t";
		if(score==-1)
		 {
		 	cout<<"out"<<"\t \t "<<p_score[i]+1<<"\t\t "<<player_balls[i]<<"\t"<<fours_team1[i]<<"\t"<<six_team1[i]<<"\t"<<setprecision(2)<<fixed<<Sr_team1[i];
		 	
		 	
		 	
		 	
		 	team_score(p_score,score,balls,wickets,i,team_s,ov,balls_over,ove);
		 	baller_card(team2,p_score,ove);
			i++;
		
		 	cout<<endl;
		 	
		 	
		 }
		 else
		 {
			  	cout<<"Not OUT "<<"  "<<"["<<score<<"]   "<<p_score[i]<<"\t\t "<< player_balls[i]<<"\t"<<fours_team1[i]<<"\t"<<six_team1[i]<<"\t"<<setprecision(2)<<fixed<<Sr_team1[i];
	  		cout<<endl;
	  		team_score(p_score,score,balls,wickets,i,team_s,ov,balls_over,ove);
	  		cout<<endl;
		}
		ove--;
	}
	else
	{
	innings1(score,balls,player_balls, p_score,fours_team1, six_team1, Sr_team1, team1, i,wickets,team_s,ov,balls_over);
	baller_card(team2,p_score,ove);
	}
}
void baller_card(char team2[][15],int p_score[11],int &ove)
{
	string bowler;
//	int innings_over;
//	int overs_per_bowler;
//	int c=0;
	int Overs = ove/6;
	int overs=Overs/5;
	int j=10;
	int x=0;
/*	for(int x=0;x<ove;x++)
	{
		for(int z=0;z<6;z++)
		{
			team2[j-c];
		} 
		c++;
	}*/
	
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"BOWLING"<<"\t\t\t\t"<<"O"<<"\t\t"<<"M"<<"\t\t"<<"R"<<"\t\t"<<"W"<<"\t\t"<<"Econ"<<"\t\t"<<"Wd"<<"\t\t"<<"NB"<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<" "<<"1"<<" "<<("%s\n",team2[j])<<"\t\t\t\t"<<overs<<"\t\t"<<"0"<<"\t\t"<<p_score[x]<<"\t\t"<<"0"<<"\t\t"<<"8.85"<<"\t\t"<<"0"<<"\t\t"<<"0"<<endl;
	cout<<" "<<"2"<<" "<<("%s\n",team2[j-1])<<"\t\t\t\t"<<overs<<"\t\t"<<"0"<<"\t\t"<<p_score[x+1]<<"\t\t"<<"0"<<"\t\t"<<"15.67"<<"\t\t"<<"0"<<"\t\t"<<"0"<<"\t\t"<<endl;
	cout<<" "<<"3"<<" "<<("%s\n",team2[j-2])<<"\t\t\t\t"<<overs<<"\t\t"<<"0"<<"\t\t"<<p_score[x+2]<<"\t\t"<<"0"<<"\t\t"<<"5.92"<<"\t\t"<<"0"<<"\t\t"<<"0"<<endl;
	cout<<" "<<"4"<<" "<<("%s\n",team2[j-3])<<"\t\t\t\t"<<overs<<"\t\t"<<"0"<<"\t\t"<<p_score[x+3]<<"\t\t"<<"0"<<"\t\t"<<"6.61"<<"\t\t"<<"0"<<"\t\t"<<"0"<<endl;
	cout<<" "<<"5"<<" "<<("%s\n",team2[j-4])<<"\t\t\t\t"<<overs<<"\t\t"<<"0"<<"\t\t"<<p_score[x+4]<<"\t\t"<<"0"<<"\t\t"<<"8.27"<<"\t\t"<<"0"<<"\t\t"<<"0"<<endl;
//
//	overs_per_bowler=innings_over/5;
	
}



void team_score(int p_score[11],int &score,float &balls,int &wicket,int i,int &team_s,int &ov,int &balls_over,int &ove)
{
	
	
	//counting over number and number of balls separately
	
	int ba=balls;
	float RR;
	int f;
	team_s+= score;
	
	f=ove*6;
	if(ba % 6 == 0 && ov<=f)
	{
		
		ov +=1;
		if(ov>f)
	{
			ov-=1;
	}
		balls_over=0;
	}
	else
	{
		
		
		balls_over+=1;
	}
	
	
	cout<<endl;
	if(score == -1)
	{
		team_s +=1;
		
	}
	RR=run_rate(team_s,balls);	
	cout<<endl<<endl<<endl<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"TOTAL "<<"\t\t"<<ov<<"."<<balls_over<<"overs "<<"( RR : "<<RR<<" )";
	cout<<"\t\t\t"<<team_s<<"/"<<wicket<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
}


string batsman(char team1[][15],int i)
{	
		
		return team1[i];

}

float run_rate(int &team_s, float &balls)
{
	float r,ove;
	ove=balls/6.0;
	r= team_s/ove;
	return r;
}

void result(int &team_s,int &team2_s,char team1[][15],char team2[][15],int p_score[11],int p_score_team2[11]) 
{
	int difference_score=0;
	string match_batsman;
	string winner;
	 ofstream file2("Result.txt");
		
	
	if(team_s>team2_s)
	{
		difference_score = team_s-team2_s;
		match_batsman=MoM(team1,p_score);
		winner="Pakistan";
		 file2<<winner<<" won the match : "<<difference_score<<endl;
	}
	else
	{
		winner="Kachra 11";
		difference_score = team2_s-team_s;
		match_batsman=MoM2(team2,p_score_team2);
		 file2<<winner<<" won the match by : "<<difference_score<<" runs"<<endl;
	}
		
		 //file<<"Best Bowler of the match : "<<BoM<<endl;
		 file2<<"Best Batsman of the match : "<<match_batsman<<endl;
	 	file2.close();
	 	cout<<endl;
	
	 
	 ifstream File2("Result.txt");
	 cout<<"CONGRATULATIONS"<<endl;
	 
		 cout<<winner<<" won the match : "<<difference_score<<" runs"<<endl;
	
		
		// cout<<"Best Bowler of the match : "<<BoM<<endl;
		 cout<<"Best Batsman of the match : "<<match_batsman<<endl;
	 //clearing window
	 cin.ignore();
	 cout<<"Press Enter to continue "<<endl;
	cin.get();
	system("clear");
	
}
								//Autoplay
/*
void desired_over()
{
	int a;
	char ans;
	a=get_overs(count);
	int b;
	cout<<"Do you want to Autoplay"<<endl;
	cin>>ans;
	if(ans == 'y')
	{
		cout<<"Enter over for autoplay"<<endl;
		cin>>b;
		while(b > a)
		{
			cout<<"The move is invalid"<<endl; 
		}
		
	} 
}*/
void innings1(int &score, float &balls,int player_balls[11],int p_score[11],int fours_team1[11], int six_team1[11],float Sr_team1[11],char team1[][15],int i,int &wickets,int &team_s,int &ov,int &balls_over)

{
	cout<<endl;
	cout<<"\t\t\t\tINNINGS PAKISTAN"<<endl;
	cout<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"BATTING"<<"\t\t\t\t"<<" R"<<" \t\t"<<" B"<<"\t"<<"4s"<<"\t"<<"6s"<<"\t"<<"SR"<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<endl;
	
	for(int k=0;k<11;k++)
	{
		cout<<" "<<k+1<<" "<<("%s\n",team1[k]);
		if(score<0)
		{
			
			cout<<"\t\t\t\t"<<p_score[k];
		}
		else
		{
			cout<<"\t\t\t\t"<<p_score[k];
		}
		cout<<"\t\t"<<player_balls[k];
		cout<<"\t"<<fours_team1[k];
		cout<<"\t"<<six_team1[k];
		cout<<"\t"<<Sr_team1[k];
		cout<<endl;
	}
}
string MoM(char team1[][15],int p_score[11])
{
	string batsmanmatch;
	batsmanmatch=("%s\n",team1[0]);
	for (int i = 0; i < 11; i++) 
	{
    		if (p_score[0] < p_score[i]) 
    		{
      			batsmanmatch = ("%s\n",team1[i]);
 		}
	}
	return batsmanmatch;
}
string MoM2(char team2[][15],int p_score_team2[11])
{
	string batsmanmatch2;
	batsmanmatch2=("%s\n",team2[0]);
	for (int m = 0; m < 11; m++) 
	{
    		if (p_score_team2[0] < p_score_team2[m]) 
    		{
      			batsmanmatch2 = ("%s\n",team2[m]);
 		}
 		
	}
	return batsmanmatch2;
}



//---------------------------------------------------------------------------------------------------------------------------------------------


int Score_team2(int p_score_team2[11],char team1[][15],char team2[][15],int m,int &ove2,int &wickets_team2,int &team2_s,int &ov2,int &balls_over2,int &q,int count2,int j)
{
	

//---------------------------------------------------------------------------------------------------------------------

//	int p_score_team2[11]={0};
	int fours_team2[11]={0};
	int six_team2[11]={0};
	int player_balls_team2[11]={0};
	//int count2=1;
	int player_balls_count2=1;
	float balls2=0;
	srand(time(NULL));
	int score2 = 0;
	int innings_balls2=ove2;
	float Sr_team2[11]={0};
	float total_score2 = 0;
	int F=0,S=0;
	
	
	while (wickets_team2!=10 && innings_balls2!=0)
	{
		if(score2==-1)
		{
			p_score_team2[m]=p_score_team2[m]+1;
			m++;
			wickets_team2++;
			total_score2=0;
			F=0;
			S=0;
			player_balls_count2=1;
			
		}
		
		balls2=count2;
		player_balls_team2[m]=player_balls_count2;
		score2 = (rand()%8) - 1;
		if(score2 == 4)
		{
			F++;
		}
		if (score2 == 6)
		{
			S++;
		}
		fours_team2[m]=F;
		six_team2[m]=S;
		
	/*	if(score2 ==1 || score2==3 || score2==5 || count2%6==0)
		{
			if (q%2 ==0)
			{
				m--;
				q++;
			}
			else
			{
				m++;
				q++;
			}
		}
		*/
		total_score2 += score2;
		p_score_team2[m]+=score2;
		Sr_team2[m]= (p_score_team2[m]/balls2)*100;
		drawScoreCard_team2(score2,balls2,player_balls_team2,p_score_team2,fours_team2,six_team2,Sr_team2, team2,m,wickets_team2,team2_s,ov2,balls_over2,ove2,team1,j);
		
		count2++;
		player_balls_count2++;
		innings_balls2--;
		
		cin.get();
		system("clear");
	
	}
	
	drawScoreCard_team2(score2,balls2,player_balls_team2,p_score_team2,fours_team2,six_team2,Sr_team2, team2,m,wickets_team2,team2_s,ov2,balls_over2,ove2,team1,j);
	
	innings2(score2,balls2,player_balls_team2, p_score_team2,fours_team2, six_team2, Sr_team2, team2, m,wickets_team2,team2_s,ov2,balls_over2,ove2);
		baller_card2(team1,j,p_score_team2,ove2);
	
	
	
	return 0;	

}
void drawScoreCard_team2( int &score2,float &balls2,int player_balls_team2[11], int p_score_team2[11],int fours_team2[11],int six_team2[11],float Sr_team2[11], char team2[][15],int m,int &wickets_team2,int &team2_s,int &ov2,int &balls_over2,int &ove2,char team1[][15],int j)
{
	int b2=player_balls_team2[m];
	
	string bat_2;
	int to_score2=p_score_team2[m];
	
	
	if(wickets_team2!=10 || ove2!=0)
	{
	cout<<"\t\t\t\tKACHRA 11"<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"BATTING"<<"\t\t\t\t"<<" R"<<" \t\t"<<" B"<<"\t"<<"4s"<<"\t"<<"6s"<<"\t"<<"SR"<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;


		bat_2=	batsman_team2(team2,m);
		
		cout<<bat_2<<"\t\t";
		if(score2==-1)
		 {
		 	cout<<"out"<<"\t \t "<<p_score_team2[m]+1<<"\t\t "<<player_balls_team2[m]<<"\t"<<fours_team2[m]<<"\t"<<six_team2[m]<<"\t"<<setprecision(2)<<fixed<<Sr_team2[m];
		 	
		 	
		 	
		 	
		 	team2_score(p_score_team2,score2,balls2,wickets_team2,m,team2_s,ov2,balls_over2,ove2);
		 	baller_card2(team1,j,p_score_team2,ove2);
			m++;
		
		 	cout<<endl;
		 	
		 	
		 }
		 else
		 {
			  	cout<<"Not OUT "<<"  "<<"["<<score2<<"]   "<<p_score_team2[m]<<"\t\t "<< player_balls_team2[m]<<"\t"<<fours_team2[m]<<"\t"<<six_team2[m]<<"\t"<<setprecision(2)<<fixed<<Sr_team2[m];
	  		cout<<endl;
	  		team2_score(p_score_team2,score2,balls2,wickets_team2,m,team2_s,ov2,balls_over2,ove2);
	  		cout<<endl;
		}
		ove2--;
	}
	else
	{
	innings2(score2,balls2,player_balls_team2, p_score_team2,fours_team2, six_team2, Sr_team2, team2, m,wickets_team2,team2_s,ov2,balls_over2,ove2);
	}
}
void baller_card2(char team1[][15],int j,int p_score_team2[11],int &ove2)
{
	string bowler;
	int Overs2=ove2/6;
	int overs2=Overs2/5;
	int y=0;
	//int innings_over;
	//int overs_per_bowler;
	//int c=0;
	/*for(int x=0;x<ove;x++)
	{
		for(int z=0;z<6;z++)
		{
			team1[j-c];
		} 
		c++;
	}*/
	
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"BOWLING"<<"\t\t\t\t"<<"O"<<"\t\t"<<"M"<<"\t\t"<<"R"<<"\t\t"<<"W"<<"\t\t"<<"Econ"<<"\t\t"<<"Wd"<<"\t\t"<<"NB"<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<" "<<"1"<<" "<<("%s\n",team1[j])<<"\t\t\t\t"<<overs2<<"\t\t"<<"0"<<"\t\t"<<p_score_team2[y]<<"\t\t"<<"0"<<"\t\t"<<"7.69"<<"\t\t"<<"0"<<"\t\t"<<"0"<<endl;
	cout<<" "<<"2"<<" "<<("%s\n",team1[j-1])<<"\t\t\t\t"<<overs2<<"\t\t"<<"0"<<"\t\t"<<p_score_team2[y+1]<<"\t\t"<<"0"<<"\t\t"<<"13.6"<<"\t\t"<<"0"<<"\t\t"<<"0"<<endl;
	cout<<" "<<"3"<<" "<<("%s\n",team1[j-2])<<"\t\t\t\t"<<overs2<<"\t\t"<<"0"<<"\t\t"<<p_score_team2[y+2]<<"\t\t"<<"0"<<"\t\t"<<"5.21"<<"\t\t"<<"0"<<"\t\t"<<"0"<<endl;
	cout<<" "<<"4"<<" "<<("%s\n",team1[j-3])<<"\t\t\t\t"<<overs2<<"\t\t"<<"0"<<"\t\t"<<p_score_team2[y+3]<<"\t\t"<<"0"<<"\t\t"<<"4.44"<<"\t\t"<<"0"<<"\t\t"<<"0"<<endl;
	cout<<" "<<"5"<<" "<<("%s\n",team1[j-4])<<"\t\t\t\t"<<overs2<<"\t\t"<<"0"<<"\t\t"<<p_score_team2[y+4]<<"\t\t"<<"0"<<"\t\t"<<"3.80"<<"\t\t"<<"0"<<"\t\t"<<"0"<<endl;
//	innings_over=get_overs(count);
//	overs_per_bowler=innings_over/5;
	
}



void team2_score(int p_score_team2[11],int &score2,float &balls2,int &wicket_team2,int m,int &team2_s,int &ov2,int &balls_over2,int &ove2)
{
	
	
	
	
	int ba2=balls2;
	float RR2;
	int f;
	//f=ove2*6;
	team2_s+= score2;
	/*if(ov2 > ove2)
	{
		ov2=0;
	}*/
	
	if(ba2 % 6 == 0)
	{
		ov2 +=1;
		balls_over2=0;
	}
	else
	{
		
		
		balls_over2+=1;
	}
	
	
	cout<<endl;
	if(score2 == -1)
	{
		team2_s +=1;
		
	}
	RR2=run_rate_team2(team2_s,balls2);	
	cout<<endl<<endl<<endl<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"TOTAL "<<"\t\t"<<ov2<<"."<<balls_over2<<"overs "<<"( RR : "<<RR2<<" )";
	cout<<"\t\t\t"<<team2_s<<"/"<<wicket_team2<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
}


string batsman_team2(char team2[][15],int m)
{	

		return team2[m];

}

float run_rate_team2(int &team2_s, float &balls2)
{
	float r2,ove;
	ove=balls2/6.0;
	r2= team2_s/ove;
	return r2;
}
void innings2(int &score2, float &balls,int player_balls_team2[11],int p_score_team2[11],int fours_team2[11], int six_team2[11],float Sr_team2[11],char team2[][15],int i,int &wickets_team2,int &team2_s,int &ov,int &balls_over,int &ove2)

{
	cout<<endl;
	cout<<"\t\t\t\tINNINGS KACHRA 11"<<endl;
	cout<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"BATTING"<<"\t\t\t\t"<<" R"<<" \t\t"<<" B"<<"\t"<<"4s"<<"\t"<<"6s"<<"\t"<<"SR"<<endl;
	cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
	cout<<endl;
	
	for(int k=0;k<11;k++)
	{
		cout<<" "<<k+1<<" "<<("%s\n",team2[k]);
		if(score2==-1)
		{
			cout<<"\t\t\t\t"<<p_score_team2[k];
		}
		else
		{
			cout<<"\t\t\t\t"<<p_score_team2[k];
		}
		cout<<"\t\t"<<player_balls_team2[k];
		cout<<"\t"<<fours_team2[k];
		cout<<"\t"<<six_team2[k];
		cout<<"\t"<<Sr_team2[k];
		cout<<endl;
	}
}

