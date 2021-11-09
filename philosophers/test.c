/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:05:43 by nabboudi          #+#    #+#             */
/*   Updated: 2021/11/09 17:05:44 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
 
struct student_college_detail
{
    int colle ge_id;
    char college_name[50];
};
 
struct student_detail 
{
    int id;
    char name[20];
    float percentage;
    struct student_college_detail *clg_data;
}stu_data;
 
int main() 
{
    struct student_college_detail b= 
    struct student_detail stu_data = {1, "Raju", 90.5, 71145,
                                       "Anna University", &b};
    printf(" Id is: %d \n", stu_data.id);
    printf(" Name is: %s \n", stu_data.name);
    printf(" Percentage is: %f \n\n", stu_data.percentage);
 
    printf(" College Id is: %d \n", 
                    stu_data.clg_data->college_id);
    printf(" College Name is: %s \n", 
                    stu_data.clg_data.college_name);
    return 0;
}