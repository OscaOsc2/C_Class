// 11월 24일까지 제출 

// Subject: 도서관 책의 정렬과 탐색 알고리즘. 

// 1. 청구기호 (총류-철학-종교-사회과학-자연-기술과학-예술-언어-문학-역사) 
// 2. 저자기호 (
// 3. 도서기호 (ㄱ-ㄴ-ㄷ-ㄹ-ㅁ-ㅂ-ㅅ-ㅇ-ㅈ-ㅊ-ㅋ-ㅌ-ㅍ-ㅎ)

//	정렬: 도서를 순서대로 정리하기 
//		2. 선택정렬 (도서가 비어있는 칸에 도서들을 순서대로 정렬).

//	탐색: 원하는 책을 효율적으로 찾기 
//		1. 선형탐색 (순서대로 확인하면서 탐색하기). 

//	참고 (한국십진분류법): 
//		https://namu.wiki/w/%ED%95%9C%EA%B5%AD%EC%8B%AD%EC%A7%84%EB%B6%84%EB%A5%98%EB%B2%95 


#include<stdio.h>
#include <string.h>

struct Book
{
	unsigned short genre;	// 분야 
	char writer[50];		// 저자 
	char title[50];			// 제목 
}Books;

void selection_sort(struct Book books[], int n)
{
        for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {

            // 1) genre 먼저 비교
            if (books[j].genre < books[minIndex].genre) {
                minIndex = j;
            }
            // 2) genre 같으면 writer 비교
            else if (books[j].genre == books[minIndex].genre &&
                     strcmp(books[j].writer, books[minIndex].writer) < 0) {
                minIndex = j;
            }
            // 3) genre, writer 모두 같으면 title 비교
            else if (books[j].genre == books[minIndex].genre &&
                     strcmp(books[j].writer, books[minIndex].writer) == 0 &&
                     strcmp(books[j].title, books[minIndex].title) < 0) {
                minIndex = j;
            }
        }

        // swap
        if (minIndex != i) {
            struct Book temp = books[i];
            books[i] = books[minIndex];
            books[minIndex] = temp;
        }
    }
}


int main(void)
{
    struct Book books[50];
    
    
	unsigned char n;
    printf("정렬할 책의 수: ");
	scanf("%hhu", &n);
    
	
	for(unsigned char i=0;i<n;i++){
        printf("\n책 분야\n");
        printf("0. 총류\n");
        printf("1. 철학\n");
        printf("2. 종교\n");
        printf("3. 사회과학\n");
        printf("4. 자연과학\n");
        printf("5. 기술과학\n");
        printf("6. 예술\n");
        printf("7. 언어\n");
        printf("8. 문학\n");
        printf("9. 역사\n");
        printf("답: ");
        scanf("%hu", &books[i].genre);
        
        printf("\n저자: ");
        scanf("%s", books[i].writer);

        printf("\n제목: ");
        scanf("%s", books[i].title);
	}

    selection_sort(books, n);

    printf("\n=== 정렬된 도서 목록 ===\n");
    for (unsigned char i = 0; i < n; i++) {
        printf("[%d] (%hu) %s - %s\n",
               i + 1,
               books[i].genre,
               books[i].writer,
               books[i].title);
    }

    return 0;
} 


