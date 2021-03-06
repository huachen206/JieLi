//
//  CommentViewController.m
//  JieliPublishingA
//
//  Created by 花 晨 on 13-3-6.
//  Copyright (c) 2013年 中卡. All rights reserved.
//

#import "CommentViewController.h"
#import "AppDelegate.h"
#import "SubComView.h"
#import "CommentCell.h"

#define ISLOGED [AppDelegate dAccountName]?1:0
@interface CommentViewController ()

@end

@implementation CommentViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        
        
    }
    return self;
}
-(void)iWantComment{
    
    UIActionSheet *actionSheet;
    NSString *title;
    NSString *messageA =@"登录评价";
    NSString *messageB =@"匿名评价";
    int tag ;
    if (ISLOGED) {
        tag = 1;
        title = [NSString stringWithFormat:@"您已登录:%@",[AppDelegate dAccountName]];
    }
    else {
        tag = 2;
        title = @"您还未登录";
    }
    actionSheet = [[UIActionSheet alloc] initWithTitle:title delegate:self cancelButtonTitle:@"返回" destructiveButtonTitle:messageA otherButtonTitles:messageB, nil];
    actionSheet.tag = tag;
    [actionSheet showInView:self.view.superview.superview];
    
//    actionSheet = [[UIActionSheet alloc] initWithTitle:title delegate:self cancelButtonTitle:title destructiveButtonTitle:<#(NSString *)#> otherButtonTitles:<#(NSString *), ...#>, nil]
    
}
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex{
    NSLog(@"%d",buttonIndex);
    if (buttonIndex == 0) {
        if (!ISLOGED) {
            LogViewController *viewController = [[LogViewController alloc] initWithNibName:@"LogViewController" bundle:nil];
            viewController.finishToPop = YES;
            [self.delegate pushTo:viewController];
        }
        else{
            [self toSubComViewWithBookId:self.bookInfo.bookId useId:[AppDelegate dUserId] userName:[AppDelegate dAccountName]];
        }
    }
    else if (buttonIndex == 1){
        [self toSubComViewWithBookId:self.bookInfo.bookId useId:nil userName:nil];

    }
    
    
    
    
    

}
-(void)toSubComViewWithBookId:(NSInteger)bookId useId:(NSString *)userId userName:(NSString *)userName{
    
    SubComView *sc = [[SubComView alloc] initWithBookId:bookId userId:userId accountName:userName];
    sc.vc = self;
    [sc show];

    
}
- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
}
-(void)loadBookInfo:(BookInfo *)info{
    self.bookInfo = info;
    CommentPoeration *op = [CommentPoeration getWithTaget:self withBookId:info.bookId];
    op.delegate = self;
    [[AppDelegate shareQueue] addOperation:op];
    
}


-(void)getCommentFinish:(id)r{
    NSLog(@"getCommentFinish:::%@",r);
    if (!r) {
        return;
    }
    [self.noCommentImageView setHidden:YES];
    self.array0fcells = nil;
    self.array0fcells = [[CommentCell cellsForData:r] retain];
    [self.tableView reloadData];
}

#pragma mark --
#pragma mark TableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [self.array0fcells count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    CommentCell *cell = (CommentCell *)[self.array0fcells objectAtIndex:indexPath.row];
    return cell.frame.size.height;
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{

    NSLog(@"%d",indexPath.row);
    return [self.array0fcells objectAtIndex:indexPath.row];
}
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    CommentCell *cell = [CommentCell cellFromCell:[self.array0fcells objectAtIndex:indexPath.row]];
    [self.array0fcells replaceObjectAtIndex:indexPath.row withObject:cell];
    [tableView reloadRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    
}



- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (void)dealloc {
    [_tableView release];
    [_noCommentImageView release];
    [super dealloc];
}
- (void)viewDidUnload {
    [self setTableView:nil];
    [self setNoCommentImageView:nil];
    [super viewDidUnload];
}
@end
