// 11월 24일까지 제출 

// Subject: 도서관 책의 정렬과 탐색 알고리즘. 

// 1. 청구기호 (총류-철학-종교-사회과학-자연-기술과학-예술-언어-문학-역사) 
// 2. 저자기호 (
// 3. 도서기호 (ㄱ-ㄴ-ㄷ-ㄹ-ㅁ-ㅂ-ㅅ-ㅇ-ㅈ-ㅊ-ㅋ-ㅌ-ㅍ-ㅎ)
// 4. 시리즈 (v.1 - v.2 - ...) 

//	정렬: 도서를 순서대로 정리하기 
//		1. 삽입정렬 (정렬이 완료된 도서들 속에 정렬할 도서들을 삽입하기).
//		2. 선택정렬 (도서가 비어있는 칸에 도서들을 순서대로 정렬).

//	탐색: 원하는 책을 효율적으로 찾기 
//		1. 선형탐색 (순서대로 확인하면서 탐색하기). 

//	참고 (한국십진분류법): 
//		https://namu.wiki/w/%ED%95%9C%EA%B5%AD%EC%8B%AD%EC%A7%84%EB%B6%84%EB%A5%98%EB%B2%95 


#include<stdio.h>

struct Books
{
	unsigned short genre;	// 분야 
	char writer[100];			// 저자 
	string title[100];			// 제목 
	unsigned short series;	// 시리즈
}Book;

int claimNumber(int genreNum)


int main(void)
{
	unsigned char n;
	scanf("정렬할 책의 수: %d" &n);
	
	for(unsigned char i=0;i<n;i++){
		print("")
	}
} 

