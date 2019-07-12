/**
 *  This function checks if the passed character is a symbol or not.
 * @param a of type char
 * @return 1 if a symbol else 0
 */
int issymbol(char a){
	switch(a){
		case '^':
		case '~':
		case '>':
		case 'V':
		case '(':
		case ')':
		return 1;
		break;
		default: return 0;

	}
}
