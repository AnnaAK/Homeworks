int Bigger (node **num1, node **num2)
{
	node *temp1 = *num1;
	node *temp2 = *num2;
	int val1 = 0, val2 = 0;
	int big = 0;
	while (temp1 != NULL || temp2 != NULL)
  {
      if (temp1 != NULL)
      {
		  val1 = temp1->val;
		  temp1 = temp1->next;
      }
	  else
	  {
		  return 0;
	  }
      if (temp2 != NULL)
      {
         val2 = temp2->val;
		 temp2 = temp2->next;
      }
	  else 
	  { 
		  return 1;
	  }
	  if (val1 > val2)
	  {
		  big = 1;
	  }
	  else
	  {
		  big = 0;
	  }
	  return big;
	}
}


LongNum* LongNum_empty () 
{
	
LongNum *temp = (LongNum*)malloc(sizeof (LongNum));
if (temp != NULL)
   {
      temp->sign = 0;
      temp->digits = NULL;
      return temp;
   }
   else printf("Not enough memory\n");
}

void LongNum_enter(LongNum **num,char num1) 
{
   char digit = num1;
   if (digit == '-') (*num)->sign = 1;
   else if (digit < '0' || digit > '9')  
   {
	   (*num)->sign = (int)'E';
	   return;
   }
   else List_additionElement(&(*num)->digits, (int)digit - (int)'0');
   while (digit != ' ')
   {
       scanf("%c", &digit);
       if (digit < '0' || digit > '9')
       { 
           (*num)->sign = (int)'E';
	       return;
	   }
       List_additionElement(&(*num)->digits, (int)digit - (int)'0');
   }
   return;
}


void LongNum_revert(LongNum **num)
{
	node *result = NULL;
	node *temp = (*num)->digits;
	int sign = (*num)->sign;

	while(temp != NULL)
	{
		List_additionElement(&result, temp->val);
		temp = temp->next;
	}
	LongNum_clear(num);
	(*num)->digits = result;
	(*num)->sign = sign;
	return;
}

void LongNum_clear (LongNum **num)
{
	List_clear(&(*num)->digits);
	(*num)->sign = 0;
	return;
}


void LongNum_delete (LongNum **num)
{
	LongNum_clear(num);
	free(*num);
	return;
}

void LongNum_sum (LongNum **num1, LongNum **num2, LongNum **result)
{
  node *temp1 = (*num1)->digits;
  node *temp2 = (*num2)->digits;
  int curr = 0;
  while (temp1 != NULL || temp2 != NULL)
  {
      if (temp1 != NULL)
      {
        curr = curr + temp1->val;
        temp1 = temp1->next;
      }
      if (temp2 != NULL)
      {
        curr = curr + temp2->val;
        temp2 = temp2->next;
      }
      List_additionElement(&(*result)->digits, curr % 10);
      curr = curr / 10;
  }
  if (curr)
    List_additionElement(&(*result)->digits, curr);
  return ;
}




void LongNum_multi(LongNum **num1, LongNum **num2, LongNum **result)
{
	node *temp1 = (*num1)->digits;
    node *temp2 = (*num2)->digits;
    node *temp = NULL;
    LongNum *temp1S = LongNum_empty ();
    LongNum *temp2S = LongNum_empty ();
    LongNum *tempResult = LongNum_empty ();

    int curr = 0, fact = 0, i = 0, point = 0;

    if (List_size(&(*num1)->digits) > List_size(&(*num2)->digits))
	{
		while (temp2 != NULL)
	    {
			fact = temp2->val;
		    while (temp1 != NULL)
		    {
				curr = curr + fact * temp1->val;
			    List_additionElement (&temp1S->digits, curr % 10);
			    curr = curr / 10;
			    temp1 = temp1->next;
		    }
		    if (curr) List_additionElement (&temp1S->digits, curr);
		    LongNum_revert(&temp1S);
            for (i = 0; i < curr; i++) (&temp1S->digits, 0);
		    LongNum_sum (&temp1S, &temp2S,&tempResult);
		    temp = tempResult->digits;
		    while (temp != NULL)
		    {
				fact = (int)*(&temp->val);
			    List_additionElement (&(*result)->digits, fact);
			    temp = temp->next;
		    }
		    point = point + 1;
		    temp2 = temp2->next;
	   }
	   temp = temp2S->digits;
	   while (temp != NULL)
	   {
			fact = (int)*(&temp->val);
			List_additionElement (&(*result)->digits, fact);
			temp = temp->next;
	   }
    }
    return;
}

void LongNum_sub (LongNum **num1, LongNum **num2, LongNum **result)
{
	node *temp1 = (*num1)->digits;
	node *temp2 = (*num2)->digits;
	if (((*num1)->sign == 0) && ((*num2)->sign == 0))
	{
		if (List_size((*num1)->digits) > List_size((*num2)->digits))
		{
			(*result)->sign = 0;
	        while ((temp1 !=NULL) && (temp2 != NULL))
	        {
				if (temp1->val > temp2->val)
	            {
					List_additionElement (&(*result)->digits,(*num1)->digits->val - (*num2)->digits->val);
			        temp1 = temp1->next;
			        temp2 = temp2->next;
		        }
		        else
		        { 
					List_additionElement(&(*result)->digits,((temp1->val + 10) - temp2->val));
			        temp1->next->val = temp1->next->val - 1;
			        temp1 = temp1->next;
			        temp2 = temp2->next;
		        }
	       }
       }
	
	   else 
	  {
		  (*result)->sign = 1;
		  LongNum_sub ( &(*num2), &(*num1), &(*result));
	  }
	}
	else if (((*num1)->sign == 1) && ((*num2)->sign == 1))
	{
		if (List_size((*num1)->digits) < List_size((*num2)->digits))
		{
			(*result)->sign = 0;
	        while ((temp1 !=NULL) && (temp2 != NULL))
	        {
				if (temp2->val > temp1->val)
	            {
					List_additionElement (&(*result)->digits,(*num2)->digits->val - (*num1)->digits->val);
			        temp1 = temp1->next;
			        temp2 = temp2->next;
		        }
		        else
		        { 
					List_additionElement(&(*result)->digits,((temp2->val + 10) - temp1->val));
			        temp2->next->val = temp2->next->val - 1;
			        temp1 = temp1->next;
			        temp2 = temp2->next;
		        }
	       }
       }
	
	   else 
	  {
		  (*result)->sign = 1;
		  LongNum_sub ( &(*num2), &(*num1), &(*result));
	  }
	}
	else if (((*num1)->sign == 1) && ((*num2)->sign == 0))
	{
		(*result)->sign = 1;
	     LongNum_sum ( &(*num2), &(*num1), &(*result));

	}
	else if (((*num1)->sign == 0) && ((*num2)->sign == 1))
	{
		(*result)->sign = 0;
	     LongNum_sum ( &(*num2), &(*num1), &(*result));
	}
    return;
}

node* List_sub (node **num1, node **num2, node **result)
{
		while (((*num1) != NULL) && ((*num2) != NULL))
	    {
			if ((*num1)->val > (*num2)->val)
	        {
				List_additionElement (&(*result),(*num1)->val - (*num2)->val);
			    *num1 = (*num1)->next;
			    *num2 = (*num2)->next;
		    }
		    else
		    { 
				List_additionElement(&(*result),((*num1)->val + 10) - (*num2)->val);
			    (*num1)->next->val = (*num1)->next->val - 1;
			     *num1 = (*num1)->next;
			     *num2 = (*num2)->next;
		    }
	   }
		return (*result);
}
	

void LongNum_division (LongNum **num1, LongNum **num2, LongNum **result)
{
	node *temp1 = (*num1)->digits;
    node *temp2 = (*num2)->digits;
    int count = 0;
	

	if (Bigger ((*num1)->digits,(*num2)->digits))
	{
		if ((*num1)->sign == (*num2)->sign)
	    {
			(*result)->sign = 0;
			while (List_sub(&(*num1)->digits, &(*num2)->digits, &(*result)->digits->val) >= 0)
		    { 
				count = count + 1;
			    (*num1)->digits = List_sub(&(*num1)->digits, &(*num2)->digits, &(*result)->digits);
		    }
		    count = count - 1;
		}
		else if ((*num1)->sign != (*num2)->sign)
		{
			(*result)->sign = 1;
		    while (List_sub(&(*num1)->digits, &(*num2)->digits, &(*result)->digits->val) >= 0)
		    { 
				count = count + 1;
			    (*num1)->digits = List_sub(&(*num1)->digits, &(*num2)->digits, &(*result)->digits);
		    }
		    count = count - 1;
		}
	}
	else if ((List_size((*num2)->digits) == 1) && ((*num2)->digits->val == 0 ))
		printf ("Division by zero\n");
	else 
	{
		(*result)->sign = 0;
		(*result)->digits = 0;
	}
	return;
}
